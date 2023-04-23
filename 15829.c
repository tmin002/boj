#include <stdio.h>
#include <math.h>

int main(void) {
	int L;
	scanf("%d", &L);

	char str[50];
	scanf("%s", str);

	unsigned long long total = 0;
	for (int i=0; i<L; i++) {
		total += (str[i]-96)*((int)(pow(31, i))%1234567891) % 1234567891;
	}
	printf("%llu", total);
}
