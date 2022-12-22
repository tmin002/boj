#!/usr/bin/env python3
def quick_sort(ll):
    if len(ll) <= 1:
        return ll

    left, right, mid = [], [], []
    pivot = ll[0]
    for n in ll:
        if n < pivot:
            left.append(n)
        elif n > pivot:
            right.append(n)
        else:
            mid.append(n)
    
    return quick_sort(left) + mid + quick_sort(right)


import random
ll = [random.randint(1, 10000000) for _ in range(10000000)]
quick_sort(ll)