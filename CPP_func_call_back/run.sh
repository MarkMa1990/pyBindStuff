#!/bin/bash

swig -python -c++ testModule.i
python setup.py build_ext --inplace
