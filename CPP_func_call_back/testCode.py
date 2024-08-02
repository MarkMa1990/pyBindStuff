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

def func(data,data2):
    data = np.sum(data2) + data
    for d in data:
        print(d+1)

    data[0] = 1000
    return data,d

tt.setFunc(lambda x: func(x,data2=np.linspace(0,1,5)))

print("set func done")
print()

y = tt.test(x2)
print()
print(y)


def func2(x,g):
    #f = np.sum(x) + np.sum(g)
    #x1 = x + 1
    #g1 = x - 1
    #x[:] = x + 1
    x2 = np.array(x)
    x[:] = x2 + 2
    g[:] = x2 - 2
    return 10


tt.setFunc2(func2)
print("set func2 done")
print()
y = tt.test2(x2)
print()