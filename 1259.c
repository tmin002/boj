#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i,d,k,num,yn;
    while (1) {
        scanf("%d", &num);
        if (!num) break;

        int l[5] = {0};
        for (i=0; i<5 && num; i++) {
            d = num%10;
            l[i] = d;
            num = (num-d)/10;
        }

        yn = 1;
        for (k=0; k<(i/2) && yn; k++)
            yn = l[k]==l[i-1-k];
        if (yn) printf("yes\n");
        else printf("no\n");
    }
}