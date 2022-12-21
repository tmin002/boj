#include <stdio.h>
#include <stdlib.h>

void prime_factorization(int n, int * p, int * q) {
    int pq[2];
    int i,j;

    while (n>1) {
        // find dividable number
        for (i=2; i<=n; i++) {
            if (n%i == 0) {
               pq[j] = i; 
               n /= i;
               j += 1;
               break;
            }
        }
    }

    // append result
    *p = pq[0];
    *q = pq[1];
}


int main(void) {

    // init 
    int n,c,e,p,q,d,m; // variables
    int i,j,k; // counters

    // input
    FILE * f = fopen("input.txt", "r");
    if (!f) {
        printf("file not found");
    }
    fscanf(f, "n=%d, e=%d, c=%d, m=%d", &n, &e, &c, &m);

    // prime factorization
    prime_factorization(n, &p, &q);

    // get d
	for (i=1; i<=10; i++) {
		d = ((p-1)*(q-1) * i + 1)/e;
		if ((e*d) % ((p-1)*(q-1)) == 1)
			break;
	}

    // calc c^d mod m
    m = 1;
    for (i=0; i<d; i++) {
        m *= c;
    }

    // print out
    printf("%d", m%n);

}
