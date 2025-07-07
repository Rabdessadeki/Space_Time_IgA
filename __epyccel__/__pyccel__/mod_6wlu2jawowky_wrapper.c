#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#define MOD_6WLU2JAWOWKY_WRAPPER

#include "mod_6wlu2jawowky_wrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


/*........................................*/


/*........................................*/

/*........................................*/
static PyObject* bind_c_assemble_norm_ex01_wrapper(PyObject* self, PyObject* args, PyObject* kwargs)
{
    PyObject* ne1_obj;
    PyObject* ne2_obj;
    PyObject* p1_obj;
    PyObject* p2_obj;
    PyObject* spans_1_obj;
    PyObject* spans_2_obj;
    PyObject* basis_1_obj;
    PyObject* basis_2_obj;
    PyObject* weights_1_obj;
    PyObject* weights_2_obj;
    PyObject* points_1_obj;
    PyObject* points_2_obj;
    PyObject* vector_m1_obj;
    PyObject* vector_m2_obj;
    PyObject* vector_u_obj;
    PyObject* rhs_obj;
    int64_t ne1;
    int64_t ne2;
    int64_t p1;
    int64_t p2;
    t_ndarray spans_1 = {.shape = NULL};
    void* bound_spans_1;
    int64_t bound_spans_1_shape_1;
    int64_t bound_spans_1_stride_1;
    t_ndarray spans_2 = {.shape = NULL};
    void* bound_spans_2;
    int64_t bound_spans_2_shape_1;
    int64_t bound_spans_2_stride_1;
    t_ndarray basis_1 = {.shape = NULL};
    void* bound_basis_1;
    int64_t bound_basis_1_shape_1;
    int64_t bound_basis_1_shape_2;
    int64_t bound_basis_1_shape_3;
    int64_t bound_basis_1_shape_4;
    int64_t bound_basis_1_stride_1;
    int64_t bound_basis_1_stride_2;
    int64_t bound_basis_1_stride_3;
    int64_t bound_basis_1_stride_4;
    t_ndarray basis_2 = {.shape = NULL};
    void* bound_basis_2;
    int64_t bound_basis_2_shape_1;
    int64_t bound_basis_2_shape_2;
    int64_t bound_basis_2_shape_3;
    int64_t bound_basis_2_shape_4;
    int64_t bound_basis_2_stride_1;
    int64_t bound_basis_2_stride_2;
    int64_t bound_basis_2_stride_3;
    int64_t bound_basis_2_stride_4;
    t_ndarray weights_1 = {.shape = NULL};
    void* bound_weights_1;
    int64_t bound_weights_1_shape_1;
    int64_t bound_weights_1_shape_2;
    int64_t bound_weights_1_stride_1;
    int64_t bound_weights_1_stride_2;
    t_ndarray weights_2 = {.shape = NULL};
    void* bound_weights_2;
    int64_t bound_weights_2_shape_1;
    int64_t bound_weights_2_shape_2;
    int64_t bound_weights_2_stride_1;
    int64_t bound_weights_2_stride_2;
    t_ndarray points_1 = {.shape = NULL};
    void* bound_points_1;
    int64_t bound_points_1_shape_1;
    int64_t bound_points_1_shape_2;
    int64_t bound_points_1_stride_1;
    int64_t bound_points_1_stride_2;
    t_ndarray points_2 = {.shape = NULL};
    void* bound_points_2;
    int64_t bound_points_2_shape_1;
    int64_t bound_points_2_shape_2;
    int64_t bound_points_2_stride_1;
    int64_t bound_points_2_stride_2;
    t_ndarray vector_m1 = {.shape = NULL};
    void* bound_vector_m1;
    int64_t bound_vector_m1_shape_1;
    int64_t bound_vector_m1_shape_2;
    int64_t bound_vector_m1_stride_1;
    int64_t bound_vector_m1_stride_2;
    t_ndarray vector_m2 = {.shape = NULL};
    void* bound_vector_m2;
    int64_t bound_vector_m2_shape_1;
    int64_t bound_vector_m2_shape_2;
    int64_t bound_vector_m2_stride_1;
    int64_t bound_vector_m2_stride_2;
    t_ndarray vector_u = {.shape = NULL};
    void* bound_vector_u;
    int64_t bound_vector_u_shape_1;
    int64_t bound_vector_u_shape_2;
    int64_t bound_vector_u_stride_1;
    int64_t bound_vector_u_stride_2;
    t_ndarray rhs = {.shape = NULL};
    void* bound_rhs;
    int64_t bound_rhs_shape_1;
    int64_t bound_rhs_shape_2;
    int64_t bound_rhs_stride_1;
    int64_t bound_rhs_stride_2;
    static char *kwlist[] = {
        "ne1",
        "ne2",
        "p1",
        "p2",
        "spans_1",
        "spans_2",
        "basis_1",
        "basis_2",
        "weights_1",
        "weights_2",
        "points_1",
        "points_2",
        "vector_m1",
        "vector_m2",
        "vector_u",
        "rhs",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOOOOOOOOOOOOOOO", kwlist, &ne1_obj, &ne2_obj, &p1_obj, &p2_obj, &spans_1_obj, &spans_2_obj, &basis_1_obj, &basis_2_obj, &weights_1_obj, &weights_2_obj, &points_1_obj, &points_2_obj, &vector_m1_obj, &vector_m2_obj, &vector_u_obj, &rhs_obj))
    {
        return NULL;
    }
    if (PyIs_NativeInt(ne1_obj))
    {
        ne1 = PyInt64_to_Int64(ne1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument ne1");
        return NULL;
    }
    if (PyIs_NativeInt(ne2_obj))
    {
        ne2 = PyInt64_to_Int64(ne2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument ne2");
        return NULL;
    }
    if (PyIs_NativeInt(p1_obj))
    {
        p1 = PyInt64_to_Int64(p1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument p1");
        return NULL;
    }
    if (PyIs_NativeInt(p2_obj))
    {
        p2 = PyInt64_to_Int64(p2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument p2");
        return NULL;
    }
    if (pyarray_check(spans_1_obj, NPY_LONG, INT64_C(1), NO_ORDER_CHECK))
    {
        spans_1 = pyarray_to_ndarray(spans_1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument spans_1");
        return NULL;
    }
    bound_spans_1 = nd_data(&spans_1);
    bound_spans_1_shape_1 = nd_ndim(&spans_1, INT64_C(0));
    bound_spans_1_stride_1 = nd_nstep_F(&spans_1, INT64_C(0));
    if (pyarray_check(spans_2_obj, NPY_LONG, INT64_C(1), NO_ORDER_CHECK))
    {
        spans_2 = pyarray_to_ndarray(spans_2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument spans_2");
        return NULL;
    }
    bound_spans_2 = nd_data(&spans_2);
    bound_spans_2_shape_1 = nd_ndim(&spans_2, INT64_C(0));
    bound_spans_2_stride_1 = nd_nstep_F(&spans_2, INT64_C(0));
    if (pyarray_check(basis_1_obj, NPY_DOUBLE, INT64_C(4), NPY_ARRAY_C_CONTIGUOUS))
    {
        basis_1 = pyarray_to_ndarray(basis_1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument basis_1");
        return NULL;
    }
    bound_basis_1 = nd_data(&basis_1);
    bound_basis_1_shape_1 = nd_ndim(&basis_1, INT64_C(0));
    bound_basis_1_shape_2 = nd_ndim(&basis_1, INT64_C(1));
    bound_basis_1_shape_3 = nd_ndim(&basis_1, INT64_C(2));
    bound_basis_1_shape_4 = nd_ndim(&basis_1, INT64_C(3));
    bound_basis_1_stride_1 = nd_nstep_C(&basis_1, INT64_C(0));
    bound_basis_1_stride_2 = nd_nstep_C(&basis_1, INT64_C(1));
    bound_basis_1_stride_3 = nd_nstep_C(&basis_1, INT64_C(2));
    bound_basis_1_stride_4 = nd_nstep_C(&basis_1, INT64_C(3));
    if (pyarray_check(basis_2_obj, NPY_DOUBLE, INT64_C(4), NPY_ARRAY_C_CONTIGUOUS))
    {
        basis_2 = pyarray_to_ndarray(basis_2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument basis_2");
        return NULL;
    }
    bound_basis_2 = nd_data(&basis_2);
    bound_basis_2_shape_1 = nd_ndim(&basis_2, INT64_C(0));
    bound_basis_2_shape_2 = nd_ndim(&basis_2, INT64_C(1));
    bound_basis_2_shape_3 = nd_ndim(&basis_2, INT64_C(2));
    bound_basis_2_shape_4 = nd_ndim(&basis_2, INT64_C(3));
    bound_basis_2_stride_1 = nd_nstep_C(&basis_2, INT64_C(0));
    bound_basis_2_stride_2 = nd_nstep_C(&basis_2, INT64_C(1));
    bound_basis_2_stride_3 = nd_nstep_C(&basis_2, INT64_C(2));
    bound_basis_2_stride_4 = nd_nstep_C(&basis_2, INT64_C(3));
    if (pyarray_check(weights_1_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        weights_1 = pyarray_to_ndarray(weights_1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument weights_1");
        return NULL;
    }
    bound_weights_1 = nd_data(&weights_1);
    bound_weights_1_shape_1 = nd_ndim(&weights_1, INT64_C(0));
    bound_weights_1_shape_2 = nd_ndim(&weights_1, INT64_C(1));
    bound_weights_1_stride_1 = nd_nstep_C(&weights_1, INT64_C(0));
    bound_weights_1_stride_2 = nd_nstep_C(&weights_1, INT64_C(1));
    if (pyarray_check(weights_2_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        weights_2 = pyarray_to_ndarray(weights_2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument weights_2");
        return NULL;
    }
    bound_weights_2 = nd_data(&weights_2);
    bound_weights_2_shape_1 = nd_ndim(&weights_2, INT64_C(0));
    bound_weights_2_shape_2 = nd_ndim(&weights_2, INT64_C(1));
    bound_weights_2_stride_1 = nd_nstep_C(&weights_2, INT64_C(0));
    bound_weights_2_stride_2 = nd_nstep_C(&weights_2, INT64_C(1));
    if (pyarray_check(points_1_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        points_1 = pyarray_to_ndarray(points_1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument points_1");
        return NULL;
    }
    bound_points_1 = nd_data(&points_1);
    bound_points_1_shape_1 = nd_ndim(&points_1, INT64_C(0));
    bound_points_1_shape_2 = nd_ndim(&points_1, INT64_C(1));
    bound_points_1_stride_1 = nd_nstep_C(&points_1, INT64_C(0));
    bound_points_1_stride_2 = nd_nstep_C(&points_1, INT64_C(1));
    if (pyarray_check(points_2_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        points_2 = pyarray_to_ndarray(points_2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument points_2");
        return NULL;
    }
    bound_points_2 = nd_data(&points_2);
    bound_points_2_shape_1 = nd_ndim(&points_2, INT64_C(0));
    bound_points_2_shape_2 = nd_ndim(&points_2, INT64_C(1));
    bound_points_2_stride_1 = nd_nstep_C(&points_2, INT64_C(0));
    bound_points_2_stride_2 = nd_nstep_C(&points_2, INT64_C(1));
    if (pyarray_check(vector_m1_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        vector_m1 = pyarray_to_ndarray(vector_m1_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument vector_m1");
        return NULL;
    }
    bound_vector_m1 = nd_data(&vector_m1);
    bound_vector_m1_shape_1 = nd_ndim(&vector_m1, INT64_C(0));
    bound_vector_m1_shape_2 = nd_ndim(&vector_m1, INT64_C(1));
    bound_vector_m1_stride_1 = nd_nstep_C(&vector_m1, INT64_C(0));
    bound_vector_m1_stride_2 = nd_nstep_C(&vector_m1, INT64_C(1));
    if (pyarray_check(vector_m2_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        vector_m2 = pyarray_to_ndarray(vector_m2_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument vector_m2");
        return NULL;
    }
    bound_vector_m2 = nd_data(&vector_m2);
    bound_vector_m2_shape_1 = nd_ndim(&vector_m2, INT64_C(0));
    bound_vector_m2_shape_2 = nd_ndim(&vector_m2, INT64_C(1));
    bound_vector_m2_stride_1 = nd_nstep_C(&vector_m2, INT64_C(0));
    bound_vector_m2_stride_2 = nd_nstep_C(&vector_m2, INT64_C(1));
    if (pyarray_check(vector_u_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        vector_u = pyarray_to_ndarray(vector_u_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument vector_u");
        return NULL;
    }
    bound_vector_u = nd_data(&vector_u);
    bound_vector_u_shape_1 = nd_ndim(&vector_u, INT64_C(0));
    bound_vector_u_shape_2 = nd_ndim(&vector_u, INT64_C(1));
    bound_vector_u_stride_1 = nd_nstep_C(&vector_u, INT64_C(0));
    bound_vector_u_stride_2 = nd_nstep_C(&vector_u, INT64_C(1));
    if (pyarray_check(rhs_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        rhs = pyarray_to_ndarray(rhs_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type float for argument rhs");
        return NULL;
    }
    bound_rhs = nd_data(&rhs);
    bound_rhs_shape_1 = nd_ndim(&rhs, INT64_C(0));
    bound_rhs_shape_2 = nd_ndim(&rhs, INT64_C(1));
    bound_rhs_stride_1 = nd_nstep_C(&rhs, INT64_C(0));
    bound_rhs_stride_2 = nd_nstep_C(&rhs, INT64_C(1));
    bind_c_assemble_norm_ex01(ne1, ne2, p1, p2, bound_spans_1, bound_spans_1_shape_1, bound_spans_1_stride_1, bound_spans_2, bound_spans_2_shape_1, bound_spans_2_stride_1, bound_basis_1, bound_basis_1_shape_1, bound_basis_1_shape_2, bound_basis_1_shape_3, bound_basis_1_shape_4, bound_basis_1_stride_1, bound_basis_1_stride_2, bound_basis_1_stride_3, bound_basis_1_stride_4, bound_basis_2, bound_basis_2_shape_1, bound_basis_2_shape_2, bound_basis_2_shape_3, bound_basis_2_shape_4, bound_basis_2_stride_1, bound_basis_2_stride_2, bound_basis_2_stride_3, bound_basis_2_stride_4, bound_weights_1, bound_weights_1_shape_1, bound_weights_1_shape_2, bound_weights_1_stride_1, bound_weights_1_stride_2, bound_weights_2, bound_weights_2_shape_1, bound_weights_2_shape_2, bound_weights_2_stride_1, bound_weights_2_stride_2, bound_points_1, bound_points_1_shape_1, bound_points_1_shape_2, bound_points_1_stride_1, bound_points_1_stride_2, bound_points_2, bound_points_2_shape_1, bound_points_2_shape_2, bound_points_2_stride_1, bound_points_2_stride_2, bound_vector_m1, bound_vector_m1_shape_1, bound_vector_m1_shape_2, bound_vector_m1_stride_1, bound_vector_m1_stride_2, bound_vector_m2, bound_vector_m2_shape_1, bound_vector_m2_shape_2, bound_vector_m2_stride_1, bound_vector_m2_stride_2, bound_vector_u, bound_vector_u_shape_1, bound_vector_u_shape_2, bound_vector_u_stride_1, bound_vector_u_stride_2, bound_rhs, bound_rhs_shape_1, bound_rhs_shape_2, bound_rhs_stride_1, bound_rhs_stride_2);
    free_pointer(&spans_1);
    free_pointer(&spans_2);
    free_pointer(&basis_1);
    free_pointer(&basis_2);
    free_pointer(&weights_1);
    free_pointer(&weights_2);
    free_pointer(&points_1);
    free_pointer(&points_2);
    free_pointer(&vector_m1);
    free_pointer(&vector_m2);
    free_pointer(&vector_u);
    free_pointer(&rhs);
    Py_INCREF(Py_None);
    return Py_None;
}
/*........................................*/

/*........................................*/

static PyMethodDef mod_6wlu2jawowky_methods[] = {
    {
        "assemble_norm_ex01",
        (PyCFunction)bind_c_assemble_norm_ex01_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static struct PyModuleDef mod_6wlu2jawowky_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_6wlu2jawowky",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_6wlu2jawowky_methods,
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_6wlu2jawowky(void)
{
    PyObject* mod;
    static void* Pymod_6wlu2jawowky_API[0];
    PyObject* c_api_object_0001;
    mod = PyModule_Create(&mod_6wlu2jawowky_module);
    if (mod == NULL)
    {
        return NULL;
    }
    c_api_object_0001 = PyCapsule_New((void *)Pymod_6wlu2jawowky_API, "mod_6wlu2jawowky._C_API", NULL);
    if (PyModule_AddObject(mod, "_C_API", c_api_object_0001) < INT64_C(0))
    {
        Py_DECREF(mod);
        return NULL;
    }
    Py_INCREF(c_api_object_0001);
    import_array();
    return mod;
}
