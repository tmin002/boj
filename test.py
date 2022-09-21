"""n=int(input())

for i in range(n):
    tmp1=[]
    tmp=list((n-1-i)*" "+"*"*i+"&"+"*"*i+" "*(n-1-i))
    print(tmp)
    for k in tmp:
        if tmp[tmp.index(k)+1]!="&":
            if tmp[tmp.index(k)-1]!="&":
                if k=="*":
                    tmp[tmp.index(k)]="&"
    print(tmp)"""

import sys
n,m=map(int,input().split())
p1={}
p2={}
for i in range(n):
    tmp=sys.stdin.readline()
    p1[i]=tmp[:-1]
    p2[tmp]=i
for i in range(m):
    t=sys.stdin.readline()
    try:
        t=int(t)
        print(p1[t-1])
    except:
        print(p2[tmp]+1)