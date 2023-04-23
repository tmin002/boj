#!/usr/bin/env python3

a,b = list(map(int, input().split()))
aa = a
bb = b
while b != 0:
	n = a
	a = b
	b = n%b

print(a)
print(int(a * (aa/a) * (bb/a)))


