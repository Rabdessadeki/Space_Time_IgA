#ifndef MOD_DKIXTTTT6VJ0_WRAPPER_H
#define MOD_DKIXTTTT6VJ0_WRAPPER_H

#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include "cwrapper_ndarrays.h"


#ifdef MOD_DKIXTTTT6VJ0_WRAPPER

void bind_c_assemble_norm_ex01(int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t);

#else

static void** Pymod_dkixtttt6vj0_API;


/*........................................*/
static int mod_dkixtttt6vj0_import(void)
{
    PyObject* current_path;
    PyObject* stash_path;
    current_path = PySys_GetObject("path");
    stash_path = PyList_GetItem(current_path, 0);
    Py_INCREF(stash_path);
    PyList_SetItem(current_path, 0, PyUnicode_FromString("/home/rifqui/Desktop/Space_Time_IgA/__epyccel__"));
    Pymod_dkixtttt6vj0_API = (void**)PyCapsule_Import("mod_dkixtttt6vj0._C_API", 0);
    PyList_SetItem(current_path, 0, stash_path);
    return Pymod_dkixtttt6vj0_API != NULL ? 0 : -1;
}
/*........................................*/

#endif
#endif // MOD_DKIXTTTT6VJ0_WRAPPER_H
