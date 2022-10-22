n = int(input())
words = []
sort = [i for i in range(n)]
for _ in range(n): words.append(input())

def cmp(s1, s2):
    s1l, s2l = len(s1), len(s2)
    if s1l>s2l: return 1
    elif s1l<s2l: return -1
    if s1>s2: return 1
    elif s1<s2: return -1
    else: return 0

def qsort(arr):
    if not arr: return arr #empty?
    p = arr[int(len(arr)/2)]
    a = qsort([x for x in arr if cmp(words[arr[x]], words[arr[p]])==-1])
    b = qsort([x for x in arr if cmp(words[arr[x]], words[arr[p]])==1])
    return a + [x for x in arr if x == p] + b

qsort(sort)
for i in sort:
    print(words[i])