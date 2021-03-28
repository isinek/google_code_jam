#include <stdlib.h>
#include <stdio.h>

short unsigned int ask_median(short unsigned int *s, short unsigned int n, short unsigned int x)
{
	short unsigned int m;

	printf("%hu %hu %hu\n", s[0], s[n - 1], x);
	fflush(stdout);
	scanf("%hu", &m);

	return m;
}

int main()
{
	short unsigned int t, n, q, qq = 0, x, *s, i, j, l, a, b, m, tmp, mina;

	scanf("%hu %hu %hu", &t, &n, &q);

	s = (short unsigned int*) malloc(sizeof(short unsigned int)*n);
	for (x = 1; x <= t && qq < q; ++x) {
		s[0] = 1;
		s[1] = 2;
		for (i = 3; i <= n && qq < q; ++i) {
			mina = 0;
			b = i - 2;
			a = b/2;
			l = b - a + 1;
			while (l > 1 && qq < q) {
				++qq;
				m = ask_median(s + a, l, i);

				if (m == s[a]) {
					b = a;
					a = mina;
				} else if (m == i) {
					mina = a;
					a = (b + a + 1)/2;
				} else {
					mina = a = b + 1;
				}

				l = b - a + 1;
			}

			tmp = i;
			for (j = a; j < i; ++j) {
				m = s[j];
				s[j] = tmp;
				tmp = m;
			}
		}
		++qq;
		for (i = 0; i < n && qq < q; ++i)
			printf("%hu%s", s[i], i < n - 1 ? " " : "\n");
		fflush(stdout);
		scanf("%hu", &m);
		if (m != 1)
			break;
	}
	free(s);

	return 0;
}
