#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n; scanf("%d", &n);
	int prime_cnt = 0;

	for (int i=0; i<n; i++) {
		int k; scanf("%d", &k);
		int is_prime = 1;

		if (k==1) is_prime = 0;
		for (int j=2; j<k && is_prime; j++)
			if (k%j==0)
				is_prime = 0;

		prime_cnt += is_prime;
	}

	printf("%d", prime_cnt);
}
