#include <stdio.h>

int main(void) {

	int n;
	int bag_cnt = 0;
	scanf("%d", &n);

	while (n>=0) {
		if (n%5==0) {
			bag_cnt += n/5;
			break;
		}
		n -= 3;
		bag_cnt++;
	}

	printf("%d", n<0 ? -1 : bag_cnt);

}
