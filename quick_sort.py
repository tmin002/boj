def quick_sort(li):
	if len(li) <= 1:
		return li

	pivot = li[0]
	left = [i for i in li if i < pivot]
	mid = [i for i in li if i == pivot]
	right = [i for i in li if i > pivot]
	return quick_sort(left) + mid + quick_sort(right)


print(quick_sort([34,547,2435,398,25,45,69,907,45]))
