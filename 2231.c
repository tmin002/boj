#include <stdio.h>
#include <stdlib.h>


int main(void) {
	// k = n - (k의각자리수의합)

	int n; scanf("%d", &n);
	for (int i=1; i<n; i++) {

		// sum all digits
		int i_tmp = i;
		int digit_sum = 0;

		while (i_tmp > 0) {
			digit_sum += i_tmp%10;
			i_tmp = (i_tmp - i_tmp%10) / 10;
		}

		// check 
		if (i == n - digit_sum) {
			printf("%d", i);
			return 0;
		}

	}

	printf("0");
	return 0;
}
