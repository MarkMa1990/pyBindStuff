#include <iostream>
#include <Python.h>

class TestModule
{
public:

    TestModule();
    ~TestModule();
    
    void setX(double *x, int N);

    double *x0;
    int n0;

    void setFunc(PyObject *callback);

    void _print();

    PyObject* test(double *x_t, int N_t);

    void setFunc2(PyObject *callback);
    PyObject* test2(double *x_t, int N_t);

private:

    PyObject *callback_;

    PyObject *callback2_;

    
};

