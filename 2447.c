#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char txt[6561][6561] = {0};
int main(void) {
    int n; scanf("%d", &n);
    int i=3;

    for (int j=0; j<3; j++)
    for (int k=0; k<3; k++)
        if (!(j==1&&k==1))
            txt[j][k] = '*';
        else
            txt[j][k] = ' ';

    for (; i<=n/3; i*=3) {
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i][k] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i*2][k] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i*2][k+i] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i*2][k+i*2] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i][k+i*2] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j][k+i*2] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j][k+i] = txt[j][k]; 
        // step 2
        for (int j=0; j<i; j++)
        for (int k=0; k<i; k++)
            txt[j+i][k+i] = ' '; 
    }
    for (int j=0; j<i; j++) {
        for (int k=0; k<i; k++)
            printf("%c", txt[j][k]);
        printf("\n");
    }
}
