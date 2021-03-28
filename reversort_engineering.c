#include <stdlib.h>
#include <stdio.h>

int main()
{
	short unsigned int t, x, n, i, j, a, b, m[101], l[100], tmp;
	short int cost;

	scanf("%hu", &t);
	for (x = 1; x <= t; ++x) {
		scanf("%hu %hu", &n, &cost);
		if (cost < n - 1 || cost > n*((n + 1)/2.) - 1) {
			printf("Case #%hu: IMPOSSIBLE\n", x);
			continue;
		}

		for (i = 1; i <= n; ++i) {
			m[i] = i - 1;
			l[i - 1] = i;
		}

		for (i = 1; i < n && cost > n - i; ++i) {
			a = m[i];
			tmp = n - i + 1;
			b = (cost >= tmp*2 - 2)*m[n] + (cost < tmp*2 - 2)*m[i + cost - (n - i)];

			if (a > b) {
				a += b;
				b = a - b;
				a -= b;
			}
			cost -= b - a + 1;

			for (j = 0; j <= (b - a)/2; ++j) {
				tmp = l[a + j];
				l[a + j] = l[b - j];
				l[b - j] = tmp;
				m[l[a + j]] = a + j;
				m[l[b - j]] = b - j;
			}
		}

		printf("Case #%hu: ", x);
		for (i = 0; i < n; ++i) {
			if (i < n - 1)
				printf("%hu ", l[i]);
			else
				printf("%hu\n", l[i]);
		}
	}

	return 0;
}