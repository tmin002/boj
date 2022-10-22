n = int(input())
l = {0: 0, 1: 1}

addm = 1
if n==0: addm = 0
elif n<0 and abs(n)%2==0: addm = -1

for i in range(2, abs(n)+1):
    l[i] = (l[i-1] + l[i-2]) % 1000000000

print(addm)
print(l[abs(n)])