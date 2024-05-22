#include <stdio.h>
#include <math.h>

int main() {
	int i, n, j, h, cont = 0;
	double a, w;
	scanf("%d\n", &n);
	for (i = 1; i <= n; i++) {

		scanf("%d %d", &h, &w);
		a = (h - 100) * 0.9;
		if (fabs(w / 2 - a) < a * 0.1) {
			printf("You are wan mei!");
		} else {
			if (w / 2 > a) {
				printf("You are tai pang le!");
			} else
				printf("You are tai shou le!");
		}
	}

	return 0;
}
