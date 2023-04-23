#include <stdio.h>
#include <stdlib.h>

int compare (const void* first, const void* second) {
	if (*(int *)first > *(int *)second)
		return 1;
	else if (*(int *)first < *(int *)second)
		return -1;

	else
		return 0;
}

int main(void) {
	int n; scanf("%d", &n);
	int lst[1000000];

	for (int i=0; i<n; i++)
		scanf("%d", lst+i);

	qsort(lst, n, sizeof(int), compare);

	for (int i=0; i<n; i++)
		printf("%d\n", lst[i]);
	
}
