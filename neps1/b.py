from math import sqrt
from math import log

def quad(x):
    s = int(sqrt(x))
    if(s * s == x):
        return True
    else:
        return False

n = int(input())

r5 = float(sqrt(5.0))
phi = float((1.0 + r5)/2.0)

idx = int(log(n * r5) / log(phi) + 0.5)
x = int((phi ** idx) / r5 + 0.5)

if(n == 0):
    print("NAO")
elif(x == n):
    print("SIM")
else:
    print("NAO")

