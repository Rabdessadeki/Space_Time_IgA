#ifndef MOD_U8WY05J6UZUI_WRAPPER_H
#define MOD_U8WY05J6UZUI_WRAPPER_H

#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include "cwrapper_ndarrays.h"


#ifdef MOD_U8WY05J6UZUI_WRAPPER

void bind_c_assemble_vector_un_ex01_without_ddm(int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t);

#else

static void** Pymod_u8wy05j6uzui_API;


/*........................................*/
static int mod_u8wy05j6uzui_import(void)
{
    PyObject* current_path;
    PyObject* stash_path;
    current_path = PySys_GetObject("path");
    stash_path = PyList_GetItem(current_path, 0);
    Py_INCREF(stash_path);
    PyList_SetItem(current_path, 0, PyUnicode_FromString("/home/abdessadek/Desktop/PhDUM6P/Space_Time_IgA/__epyccel__"));
    Pymod_u8wy05j6uzui_API = (void**)PyCapsule_Import("mod_u8wy05j6uzui._C_API", 0);
    PyList_SetItem(current_path, 0, stash_path);
    return Pymod_u8wy05j6uzui_API != NULL ? 0 : -1;
}
/*........................................*/

#endif
#endif // MOD_U8WY05J6UZUI_WRAPPER_H
