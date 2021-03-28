#include <stdlib.h>
#include <stdio.h>

int main()
{
	int t, x, n, i, j, a, b, c, *m, *l, cost, tmp;

	scanf("%d", &t);
	for (x = 1; x <= t; ++x) {
		scanf("%d", &n);
		l = (unsigned int*) calloc(n, sizeof(unsigned int));
		m = (unsigned int*) calloc(n + 1, sizeof(unsigned int));
		cost = 0;

		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			m[tmp] = i;
			l[i] = tmp;
		}
		for (i = 1; i < n; ++i) {
			cost += 2 + m[i] - i;
			c = (2 + m[i] - i)/2;
			a = i - 1;
			b = m[i];
			for (j = 0; j < c; ++j) {
				tmp = l[a + j];
				l[a + j] = l[b - j];
				l[b - j] = tmp;
				m[l[a + j]] = a + j;
				m[l[b - j]] = b - j;
			}
		}

		printf("Case #%d: %d\n", x, cost);
		free(m);
		free(l);
	}

	return 0;
}