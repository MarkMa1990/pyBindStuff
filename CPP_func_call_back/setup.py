from setuptools import setup
from distutils.core import Extension
from setuptools import find_packages
from distutils.sysconfig import get_python_inc

import numpy as np

testModule_module=Extension('_testModule',
        sources=['testModule.cpp',
            'testModule_wrap.cxx',
            ],
        include_dirs=[np.get_include(),get_python_inc()],
        )

setup(name="testModule",
        version="0.1",
        author="Hongfeng Ma, 2024",
        description="""testModule module""",
        ext_modules=[testModule_module],
        py_modules=["testModule"],
        install_requires=['numpy'],
        packages=find_packages(include=["numpy"],),
        )
