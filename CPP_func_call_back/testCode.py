import numpy as np 
import testModule 

tt=testModule.TestModule()

print(dir(tt))

N=np.int64(10)
x=np.linspace(0,1,N, dtype=np.float64)

x2=np.linspace(0,1,20, dtype=np.float64)

tt.setX(x)

print(tt.n0)

tt._print()

#for i0 in range(tt.n0):
#    print(tt.x0[0])

def func(data):
    for d in data:
        print(d+1)
    return data

tt.setFunc(func)

print("set func done")
print()

y = tt.test(x2)
print()
print(y)

