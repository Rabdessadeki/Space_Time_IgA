#ifndef MOD_B9OI5EHZMF6B_WRAPPER_H
#define MOD_B9OI5EHZMF6B_WRAPPER_H

#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include "cwrapper_ndarrays.h"


#ifdef MOD_B9OI5EHZMF6B_WRAPPER

void bind_c_assemble_vector_ex01(int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t);

#else

static void** Pymod_b9oi5ehzmf6b_API;


/*........................................*/
static int mod_b9oi5ehzmf6b_import(void)
{
    PyObject* current_path;
    PyObject* stash_path;
    current_path = PySys_GetObject("path");
    stash_path = PyList_GetItem(current_path, 0);
    Py_INCREF(stash_path);
    PyList_SetItem(current_path, 0, PyUnicode_FromString("/home/rifqui/Desktop/Space_Time_IgA/__epyccel__"));
    Pymod_b9oi5ehzmf6b_API = (void**)PyCapsule_Import("mod_b9oi5ehzmf6b._C_API", 0);
    PyList_SetItem(current_path, 0, stash_path);
    return Pymod_b9oi5ehzmf6b_API != NULL ? 0 : -1;
}
/*........................................*/

#endif
#endif // MOD_B9OI5EHZMF6B_WRAPPER_H
