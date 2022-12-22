#!/usr/bin/env python3

def merge(li1, li2):
    i1, i2 = 0, 0
    rl = []
    while i1 < len(li1) and i2 < len(li2):
        if li1[i1] < li2[i2]:
            rl.append(li1[i1])
            i1 += 1
        else:
            rl.append(li2[i2])
            i2 += 1
    if i1 == len(li1):
        rl += li2[i2:]
    if i2 == len(li2):
        rl += li1[i1:]
    return rl

def merge_sort(li):
    len_li = len(li)
    if len_li > 2:
        left = merge_sort(li[:int(len_li/2)])
        right = merge_sort(li[int(len_li/2):])
        return merge(left, right)
    elif len_li == 2:
        if li[0] < li[1]:
            return li
        else:
            return [li[1], li[0]]
    else:
        return li

import random
ll = [random.randint(1, 10000000) for _ in range(10000000)]
merge_sort(ll)