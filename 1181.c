#include <stdio.h>
#include <stdlib.h>

int cmp(char * s1, char * s2) {
	int r = 0;
	int l = 0;
	for (int i=0;; i++) {
		if (s1[i]&&s2[i]) {
			if (!r && s1[i]>s2[i]) r = 1;
			if (!r && s1[i]<s2[i]) r = -1;
		} else {
			if (!s1[i]&&!s2[i]) l = 0;
			if (s1[i]&&!s2[i]) l = 1;
			if (!s1[i]&&s2[i]) l = -1;
			break;
		}
	}
	if (l) return l;
	return r;
}

void prt(char ** words, int * sort, int n) {
	printf("print: \n");
	for (int i=0; i<n; i++) {
		printf("#%d[%d]: %s\n", i, sort[i], words[sort[i]]);
	}
	printf("end print\n");
}
void p(char ** words, int * sort, int n, int current) {
	printf("sort: ");
	for (int i=0; i<n; i++) {
		printf("[%s]", words[sort[i]]);
		if (i==current-1) printf("\033[0;32m|\033[0;0m");
	}
	printf("\n");
}

int main(void) {
	int i,j,k,n;
	int sort[20000];
	char ** words;
	char * tmp;

	scanf("%d", &n);
	words = (char **) malloc(sizeof(char *) * n);

	for (i=0; i<n; i++) {
		words[i] = (char *) malloc(sizeof(char) * 51);
		scanf("%s", words[i]);
		sort[i] = i;
	}

	for (i=1; i<n; i++) {
		//p(words, sort, n, i);
		int idx = -1;
		for (j=0; j<i; j++) {
			char r = cmp(words[sort[i]], words[sort[j]]);
			if (r==-1) {
				idx = j;
				break;
			} else if (r==0) {
				idx = -2;
				break;
			}
		}

		if (idx==-1)
			continue;
		else if (idx==-2) {
			for (k=i+1; k<n; k++)
				sort[k-1] = sort[k];
			n--;
			i--;
		} else {
			int tmp, pocket = sort[i];
			for (k=idx; k<=i; k++) {
				tmp = sort[k];
				sort[k] = pocket;
				pocket = tmp;
			}
		}
	}

	for (i=0; i<n; i++) {
		printf("%s\n", words[i]);
	}
}
