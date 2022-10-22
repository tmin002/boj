scnt = int(input())
_s = input().split()
s = [int(i) for i in _s]
n = int(input())
s.sort()

l, h = -1, -1
for i in range(scnt-1):
    if s[i] < n < s[i+1]:
        l, h = s[i]+1, s[i+1]-1
        break

if l==-1 and h==-1:
    print(0)
else:
    print((h-n+1)*(n-l) + (h-n))

# a .... n .... b
# a,n a,n+1 .. a,b == (b-n+1)
# a+1,n a+1,n+1 .. a+1,b == (b-n+1) * (n-a)
# n-1,n, .. n-1. b n-n+1
# n, n+1 .. n, b (b-n)