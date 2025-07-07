#ifndef MOD_N1U3243E928R_WRAPPER_H
#define MOD_N1U3243E928R_WRAPPER_H

#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include "cwrapper_ndarrays.h"


#ifdef MOD_N1U3243E928R_WRAPPER

void bind_c_assemble_matrix_un_ex01(int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t);

#else

static void** Pymod_n1u3243e928r_API;


/*........................................*/
static int mod_n1u3243e928r_import(void)
{
    PyObject* current_path;
    PyObject* stash_path;
    current_path = PySys_GetObject("path");
    stash_path = PyList_GetItem(current_path, 0);
    Py_INCREF(stash_path);
    PyList_SetItem(current_path, 0, PyUnicode_FromString("/home/abdessadek/Desktop/PhDUM6P/Space_Time_IgA/__epyccel__"));
    Pymod_n1u3243e928r_API = (void**)PyCapsule_Import("mod_n1u3243e928r._C_API", 0);
    PyList_SetItem(current_path, 0, stash_path);
    return Pymod_n1u3243e928r_API != NULL ? 0 : -1;
}
/*........................................*/

#endif
#endif // MOD_N1U3243E928R_WRAPPER_H
