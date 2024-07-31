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

    void test(double *x_t, int N_t);

private:

    PyObject *callback_;

    
};

