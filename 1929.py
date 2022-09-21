from math import sqrt
n, m = map(int, input().split())
l = [i for i in range(n, m+1)]
primel = [2]
primeidx = 0
for i in range(2, int(sqrt(m))):
    for idx, item in enumerate(l):
        if item%i==0: l[idx] = 0
    while l[primeidx]==0:
        primeidx += 1
    primel.append(l[primeidx])
for i in primel:
    print(i)