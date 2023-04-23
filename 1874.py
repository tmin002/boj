#!/usr/bin/env python3

def done(result):
	print(result, end='')
	exit()

n = int(input())
goal = []
maxloc = n-1
result_str = ''

for _ in range(n):
	goal.append(int(input()))
for _ in range(goal[0]):
	result_str += '+\n'

current_max = goal[0]
for idx in range(n):
	if goal[idx] == n:
		maxloc = idx
		break

	d = goal[idx] - goal[idx+1]
	if d > 1:
		done('NO')
	elif d == 1:
		result_str += '-\n'
	elif d < 0:
		result_str += '-\n'
		for _ in range(goal[idx+1] - current_max):
			result_str += '+\n'
		current_max = goal[idx+1]

result_str += '-\n'

if maxloc >= n-1:
	done(result_str)

remains = goal[maxloc:]
for idx in range(len(remains)-1):
	if remains[idx] < remains[idx+1]:
		done('NO')
	result_str += '-\n'

done(result_str)
