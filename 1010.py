import math

def f(n):
    return int(math.factorial(n))

n=int(input())
for _ in range(n):
    a=str.split(input())
    r=int(a[0])
    n=int(a[1])
    print(int(f(n)/(f(n-r)*f(r))))