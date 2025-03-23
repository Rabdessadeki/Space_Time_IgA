from simplines import compile_kernel, apply_dirichlet

from simplines import SplineSpace
from simplines import TensorSpace
from simplines import StencilMatrix
from simplines import StencilVector
from simplines import pyccel_sol_field_2d

from simplines import build_dirichlet
#---In Poisson equation
from gallery_section_04 import assemble_vector_ex01   
from gallery_section_04 import assemble_matrix_un_ex01 
from gallery_section_04 import assemble_norm_ex01     

assemble_stiffness2D = compile_kernel(assemble_matrix_un_ex01, arity=2)
assemble_rhs         = compile_kernel(assemble_vector_ex01, arity=1)
assemble_norm_l2     = compile_kernel(assemble_norm_ex01, arity=1)

#from matplotlib.pyplot import plot, show
import matplotlib.pyplot            as     plt
from   mpl_toolkits.axes_grid1      import make_axes_locatable
from   mpl_toolkits.mplot3d         import axes3d
from   matplotlib                   import cm
from   mpl_toolkits.mplot3d.axes3d  import get_test_data
from   matplotlib.ticker            import LinearLocator, FormatStrFormatter
#..
from   scipy.sparse                 import kron
from   scipy.sparse                 import csr_matrix
from   scipy.sparse                 import csc_matrix, linalg as sla
from   numpy                        import zeros, linalg, asarray, linspace
from   numpy                        import cos, sin, pi, exp, sqrt, arctan2
from   tabulate                     import tabulate
import numpy                        as     np
import timeit
import time

#==============================================================================
#.......Poisson ALGORITHM
#==============================================================================
class poisson_2d(object):
   def __init__(self, V):
       # ++++
       stiffness           = assemble_stiffness2D(V)
     
       stiffness       = apply_dirichlet(V, stiffness)
     
       
       # ...
       M                = stiffness.tosparse()
       cond_M = linalg.cond(M.toarray())
       self.lu          = sla.splu(csc_matrix(M))
       self.cond_M      = cond_M
       self.V           = V 

   def solve(self, u_d):
       V           = self.V 
    
       # ...
       u                   = StencilVector(V.vector_space)
       # ++++
       #--Assembles a right hand side of Poisson equation
       rhs                 = StencilVector(V.vector_space)
       rhs                 = assemble_rhs( V, fields = [u_d], out = rhs )

   
       rhs              = apply_dirichlet(V, rhs)
       
       b                   = rhs.toarray()
       # ...
       x                   = self.lu.solve(b)       
       # ...
       x                   = x.reshape(V.nbasis)
       #...
       u.from_array(V, x)
       # ...
       Norm                = assemble_norm_l2(V, fields=[u]) 
       norm                = Norm.toarray()
       l2_norm             = norm[0]
       H1_norm             = norm[1]       
       return u, x, l2_norm, H1_norm, self.cond_M

degree      = 2
quad_degree = degree+3
nbpts       = 100 # FOR PLOT
RefinNumber = 2 # for refinement
table       = zeros((RefinNumber+1,6))
i           = 1
times       = []

#--------------------------------------------------------------
#..... Exact slution if offered or Dirichlet boundary condition
#--------------------------------------------------------------
#.. test 0
u_exact   = lambda x, y : sin(2.*pi*x)*sin(2.*pi*y)
# ... function at each part of the boundary

#--------------------------------------------------------------
#..... Initialisation and computing optimal mapping for 16*16
#--------------------------------------------------------------
nelements  = 16
# create the spline space for each direction
VH1        = SplineSpace(degree=degree, nelements= nelements, nderiv = 2, quad_degree = quad_degree)
VH2        = SplineSpace(degree=degree, nelements= nelements, nderiv = 2, quad_degree = quad_degree)
VH00       = TensorSpace(VH1, VH2)

# ...Assembling Dirichlet boundary condition
#--------------------------------------------------------------

print("(#=assembled Dirichlet, #=solve poisson)\n")
g        = ['sin(2.*pi*x)*sin(2.*pi*y)']
x_d, u_d = build_dirichlet(VH00, g)
print('#')

#...solve poisson
P = poisson_2d(VH00)
start = time.time()
u_pH, xuh, l2_error, H1_error, cond_M = P.solve(u_d)
times.append(time.time()- start)
xuh_uni = xuh
print('-----> L^2-error ={} -----> H^1-error = {}'.format(f"{l2_error:.2e}",  f"{H1_error:.2e}" ))
print('#')

# ... 
table[0,:] = [degree, nelements, l2_error, H1_error, cond_M, times[-1]]
#..for cpu time
i_save = 1
for nbne in range(RefinNumber):
    nelements = 2**(5+nbne)
    # create the spline space for each direction
    V1 = SplineSpace(degree=degree, nelements= nelements, nderiv = 2, quad_degree = quad_degree)
    V2 = SplineSpace(degree=degree, nelements= nelements, nderiv = 2, quad_degree = quad_degree)
    # create the tensor space
    Vh00 = TensorSpace(V1, V2)

    #---------------------------------------------------------------
    #.. Prologation by knots insertion matrix of the initial mapping
    #---------------------------------------------------------------
  	
    #-----------------------------------------
    print('#---IN-UNIFORM--MESH', nelements)
    #-----------------------------------------
    u_d   = build_dirichlet(Vh00, g)[1]
    print('#')
    # ...
    P = poisson_2d(Vh00)

    start = time.time()
    u, xuh, l2_error,  H1_error, cond         = P.solve(u_d)
    times.append(time.time()- start)
    print('#')
    # ... Update table and iteration
    table[i_save,:]                             = [degree, nelements, l2_error, H1_error,  cond, times[-1]]
    i_save                                     += 1

#---print errror results
#~~~~~~~~~~~~
if True :
    print("	\subcaption{Degree $p =",degree,"$}")
    print("	\\begin{tabular}{c|ccc|ccc}")
    print("		\hline")
    print("		 $\#$cells & $L^2$-Err & $H^1$-Err & cpu-time\\\\")
    print("		\hline")
    for i in range(0,RefinNumber+1):
        print("		",int(table[i,1]),"$\\times$", int(table[i,1]), "&", np.format_float_scientific(table[i,2], unique=False, precision=2), "&", np.format_float_scientific(table[i,3], unique=False, precision=2), "&", np.format_float_scientific(table[i,5], unique=False, precision=2),"\\\\")
    print("		\hline")
    print("	\end{tabular}")
print('\n')

#---Solution in uniform mesh
u, ux, uy, X, Y = pyccel_sol_field_2d((nbpts,nbpts),  xuh , Vh00.knots, Vh00.degree)
#.. circle 
#---Compute a mapping

# ... test 2
Sol_un = u_exact(X, Y)


fig, axes =plt.subplots() 
levelsc_un= np.linspace(np.min(u), np.max(u), 100)
im2 = plt.contourf( X, Y, u, levelsc_un, cmap= 'jet')
divider = make_axes_locatable(axes) 
cax   = divider.append_axes("right", size="5%", pad=0.05, aspect = 40) 
cbar = plt.colorbar(im2, cax=cax) 
cbar.ax.tick_params(labelsize=15) 
cbar.ax.yaxis.label.set_fontweight('bold')
# Set axes (ticks) font weight
for label in axes.get_xticklabels() + axes.get_yticklabels():
    label.set_fontweight('bold') 

fig.tight_layout()
plt.show(block=True)
plt.close()
