%module testModule

%{
    #define SWIG_FILE_WITH_INIT
    #include "testModule.h"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%numpy_typemaps(bool, NPY_UINT, int)

%apply (double *IN_ARRAY1, int DIM1) {(double *x, int N)}
%apply (double *IN_ARRAY1, int DIM1) {(double *x_t, int N_t)}

//static void *free_pyfunc(void *p) { Py_DECREF((PyObject*) p); return p; }

//extern void test(void (*ptr_func)(double *, int ));


%include "testModule.h"