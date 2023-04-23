#!/usr/bin/env python3

height, width, inv = list(map(int, input().split()))

# find min, max y axis, input
miny = 256
maxy = -1
blocks = []

for _ in range(height):
	row = list(map(int, input().split()))
	blocks.append(row)
	for b in row:
		if b < miny: miny = b
		if b > maxy: maxy = b

# do bruteforce
best_time = 250000 * 256
best_time_height = -1
for goal_y in range(miny, maxy+1):

	# must pave land to goal_y
	est_time = 0
	used_inv = 0
	for row in blocks:
		for b in row:
			if b > goal_y: 
				est_time += 2*(b - goal_y)
				used_inv -= b - goal_y
			if b < goal_y: 
				est_time += goal_y - b
				used_inv += goal_y - b

	if used_inv > inv:
		# no enough blocks
		continue
	if est_time < best_time:
		# best record
		best_time = est_time
		best_time_height = goal_y
	if est_time == best_time and goal_y > best_time_height:
		# same time but this one higher
		best_time_height = goal_y

print(best_time, best_time_height)
