#include <stdio.h>
#include <stdlib.h>
#define UINT32_MAX 4294967295

int main(void) {
    unsigned int n, k, i, d, total, min, max;
    unsigned int l[10000];
    scanf("%u %u", &n, &k);

    for (i=0; i<n; i++)
        scanf("%d", &l[i]);

    d = UINT32_MAX/2, min = 0, max = UINT32_MAX;
    while (1) {
        total = 0; 
        for (i=0; i<n; i++)
            total += l[i]/d;

        if (max-min<=1) {
            break;
        } else if (total<k) {
            max = d-1;
            d = (max+min)/2;
        } else if (total>=k) {
            min = d+1;
            d = (max+min)/2;
        }
    }

    printf("%ld", d);
}
