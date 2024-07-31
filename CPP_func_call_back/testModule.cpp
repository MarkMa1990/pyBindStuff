#include <iostream>
#include "testModule.h"

/*
class TestModule
{
public:

    TestModule();
    ~TestModule();
    
    void setX(double *x, int N);

    double *x0;
    int n0;

    double test(void (*ptr_func)(double *, int ));

    void _print();

private:

    
};

*/

TestModule::TestModule(): callback_(NULL) {}
TestModule::~TestModule(){}

void TestModule::setX(double *x, int N)
{
    x0 = (double*)malloc(sizeof(double)*N);
    n0 = N;

    for (int i=0;i<N;i++)
    {
        x0[i] = x[i];
    }
}

void TestModule::setFunc(PyObject *callback)
{

    if (!PyCallable_Check(callback)) {
        std::cerr << "Object is not callable.\n";
    } else {
        if (callback_) Py_XDECREF(callback_);
        callback_ = callback;
        Py_XINCREF(callback_);
    }
}


PyObject* TestModule::test(double *x_t, int N_t)
{
    if (!callback_) {
        std::cerr << "No callback is set.\n";
    } else {
        PyObject *args = PyTuple_New(1);
        PyObject *pyArray = PyList_New(N_t);
        for (int i = 0; i < N_t; ++i) {
            PyList_SetItem(pyArray, i, PyFloat_FromDouble(x_t[i]));
        }
        PyTuple_SetItem(args, 0, pyArray);
        
        PyObject *result = PyObject_CallObject(callback_, args);
        if (result == NULL) std::cerr << "Callback call failed.\n";
//        else Py_DECREF(result);
//        Py_DECREF(args);
        return result;
    }
    return NULL;

}

void TestModule::_print() 
{
    for (int i=0;i<n0;i++)
    {
        std::cout << "x[" << i << "] = " << x0[i] << std::endl;
    }
}

