#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* quick_sort(int* array, int array_length) {
	if (array_length <= 1) {
		return array;
	}
	if (array_length == 2) {
		if (array[0] <= array[1]) {
			return array;	
		} else {
			int* arr_return = (int*) malloc(2*sizeof(int));
			arr_return[0] = array[1];
			arr_return[1] = array[0];
			return arr_return;
		}
	}


	int i;
	int pivot = array[0];

	int* left = (int*) malloc(array_length * sizeof(int));
	int* mid = (int*) malloc(array_length * sizeof(int));
	int* right = (int*) malloc(array_length * sizeof(int));
	int left_size = 0, mid_size = 0, right_size = 0;


	for (i=0; i<array_length; i++)
		if (array[i] < pivot) {
			left[left_size++] = array[i];
		} else if (array[i] > pivot) {
			right[right_size++] = array[i];
		} else {
			mid[mid_size++] = array[i];
		}

	int* left_result = quick_sort(left, left_size);
	int* right_result = quick_sort(right, right_size);
	int* total = (int*) malloc(array_length * sizeof(int));

	for (i=0; i<left_size; i++)
		total[i] = left_result[i];
	for (i=0; i<mid_size; i++)
		total[i + left_size] = mid[i];
	for (i=0; i<right_size; i++)
		total[i + left_size + mid_size] = right_result[i];

	return total;

}

int main(void) {

	// declare
	int n;
	int i,j,k;
	int lst[500000];
	int* lst_sorted;
	int cnt[8001] = {0}; // -4000 ~ 4000
	int total = 0;

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		
		// input
		scanf("%d", lst+i);

		// total
		total += lst[i];

		// count
		cnt[lst[i] + 4000]++;
	}

	// sort list
	lst_sorted = quick_sort(lst, n);

	// 1
	double avg = (double)total / n;
	printf("%d\n", (int) round(avg));

	// 2
	printf("%d\n", lst_sorted[(n-1)/2]);

	// 3 
	int max_cnt_lst[8001];
	int max_cnt_count = 0;
	int max_cnt = -1;
	int m_min, m_min_sec;

	for (i=0; i<8001; i++) {
		if (cnt[i] > max_cnt) {
			max_cnt = cnt[i];
			max_cnt_count = 0;
			max_cnt_lst[max_cnt_count++] = i;
		} else if (cnt[i] == max_cnt) {
			max_cnt_lst[max_cnt_count++] = i;
		}
	}

	if (max_cnt_count > 1) {
		if (max_cnt_lst[0] < max_cnt_lst[1]) {
			m_min = max_cnt_lst[0];
			m_min_sec = max_cnt_lst[1];
		} else {
			m_min = max_cnt_lst[1];
			m_min_sec = max_cnt_lst[0];
		}

		for (i=2; i<max_cnt_count; i++) {
			if (max_cnt_lst[i] < m_min) {
				m_min_sec = m_min;
				m_min = max_cnt_lst[i];
			} else if (max_cnt_lst[i] < m_min_sec) {
				m_min_sec = max_cnt_lst[i];
			}
		}
		printf("%d\n", m_min_sec - 4000);
	} else {
		printf("%d\n", max_cnt_lst[0] - 4000);
	}

	// 4
	int range = lst_sorted[n-1] - lst_sorted[0];
	printf("%d\n", range < 0 ? -range : range);



}
