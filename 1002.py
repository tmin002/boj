for _ in range(int(input())):
    x1, y1, r1, x2, y2 ,r2 = [int(i) for i in input().split()]
    d = ((x1-x2)**2 + (y1-y2)**2)
    rsub, radd = (r1-r2)**2, (r1+r2)**2
    if r1==r2 and d==0: print(-1)
    elif d < rsub or radd < d: print(0)
    elif d == rsub or d == radd: print(1)
else: print(2)