#include <stdio.h>
#include <stdlib.h>

void encodeChar(char * result, char c) {
    int n, i=0;

    if (c == 32) n = 0;
    else n = c-64;

    int binl[5] = {0};
    for (i=4; i>=0 && n>1; i--) {
        binl[i] = n%2;
        if (n%2) n--;
        n /= 2;
    }
    binl[i] = n;

    for (i=0; i<5; i++)
        result[i] = binl[i] ? '1' : '0';
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (; t>=1; t--) {
        int r, c; //rxc
        scanf("%d %d ", &c, &r);

        char ** table = (char **) malloc(sizeof(char *) * c);
        for (int i=0; i<c; i++) {
            table[i] = (char *) malloc(sizeof(char) * (r+1));
            for (int j=0; j<r; j++) table[i][j] = -1;
        }

        char conchr[6];
        char * constr = malloc(sizeof(char) * (r*c + 1));
        char * constr_cur = constr;
        char * conchr_cur;
        char * inputstr = malloc(sizeof(char) * ((int)(r*c/5) + 1));
        scanf("%[^\n]s", inputstr);

        for (char * c = inputstr; *c; c++) {
            encodeChar(conchr, *c);
            conchr_cur = conchr;
            for (; *conchr_cur; conchr_cur++)
                *(constr_cur++) = *conchr_cur;
        }

        constr_cur = constr;
        int turncnt = 0; //mod value 0~3 for right,down,left,up
        int nospace = 0;
        int i=0, j=-1;
        int cnt = 0;
        while (1) {
            int prev_i=i, prev_j=j;
            switch (turncnt%4) {
                case 0: j++; break;
                case 1: i++; break;
                case 2: j--; break;
                case 3: i--; break;
            }
            if (!(0<=i && i<=c-1) || !(0<=j && j<=r-1) || table[i][j] != -1) {
                if (nospace) break;
                i = prev_i; j = prev_j;
                turncnt++;
                nospace = 1;
                continue;
            }
            nospace = 0;
            if (!*constr_cur) break;
            else table[i][j] = *(constr_cur++);
        }

        for (int i=0; i<c; i++) {
            for (int j = 0; j < r; j++) {
                if (table[i][j] == -1)
                    table[i][j] = '0';
                printf("%c", table[i][j]);
            }
        }
    } 
}
