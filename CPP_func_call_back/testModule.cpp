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

TestModule::TestModule(): callback_(NULL), callback2_(NULL) {}
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


void TestModule::setFunc2(PyObject *callback)
{

    if (!PyCallable_Check(callback)) {
        std::cerr << "Object is not callable.\n";
    } else {
        if (callback2_) Py_XDECREF(callback2_);
        callback2_ = callback;
        Py_XINCREF(callback2_);
    }
}


PyObject* TestModule::test2(double *x_t, int N_t)
{
    if (!callback2_) {
        std::cerr << "No callback is set.\n";
    } else {
        PyObject *args = PyTuple_New(2);
        PyObject *pyArray_x = PyList_New(N_t);

        for (int i = 0; i < N_t; ++i) {
            PyList_SetItem(pyArray_x, i, PyFloat_FromDouble(x_t[i]));
        }
        PyTuple_SetItem(args, 0, pyArray_x);

        std::cout << "test1 :" << std::endl;

        PyObject *pyArray_df = PyList_New(N_t);
        for (int i = 0; i < N_t; ++i) {
            PyList_SetItem(pyArray_df, i, PyFloat_FromDouble(0));
        }
        PyTuple_SetItem(args, 1, pyArray_df);

        PyObject *pyArray_f = PyObject_CallObject(callback2_, args);

        // convert the python obj into c++ dtype
        if (pyArray_f == NULL) std::cerr << "Callback call failed.\n";


        double *df_cpp = (double*)malloc(sizeof(double)*N_t);
        double  f_cpp = PyFloat_AsDouble(pyArray_f);

        std::cout << "f:" << f_cpp << std::endl;

        for (int i = 0; i < N_t; ++i) 
        {
            x_t[i] = PyFloat_AsDouble(PyList_GetItem(pyArray_x, i));
            df_cpp[i] = PyFloat_AsDouble(PyList_GetItem(pyArray_df, i));

            std::cout << "x["<< i <<"]: " << x_t[i] << " df["<< i <<"]: " << df_cpp[i] << std::endl;
        }

//        else Py_DECREF(result);
//        Py_DECREF(args);
        return pyArray_f;
    }

    return NULL;

}