n = int(input())
r = input().split()
l = [int(i) for i in r]
l.sort()
print(l[0]*l[-1])