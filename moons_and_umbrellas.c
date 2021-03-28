#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long int simple_method(short int x, short int y, char *s)
{
	short unsigned int i, j, n = strlen(s);
	long long int cost = 0, tmpCostJ, tmpCostC;

	for (i = 0; i < n; ++i) {
		if (i > 0 && s[i] != '?') {
			cost += (s[i - 1] == 'C' && s[i] == 'J')*x + (s[i - 1] == 'J' && s[i] == 'C')*y;
		} else if (i == 0 && s[i] == '?') {
			for (j = 1; j < n; ++j) {
				if (s[j] != '?') {
					s[0] = s[j];
					break;
				}
			}
		} else if (s[i] == '?') {
			tmpCostJ = tmpCostC = 0;
			tmpCostJ += (i > 0 && s[i - 1] == 'C')*x + (i + 1 < n && s[i + 1] == 'C')*y;
			tmpCostC += (i > 0 && s[i - 1] == 'J')*y + (i + 1 < n && s[i + 1] == 'J')*x;

			if (tmpCostJ < tmpCostC) {
				cost += (i > 0 && s[i - 1] == 'C')*x;
				s[i] = 'J';
			} else {
				cost += (i > 0 && s[i - 1] == 'J')*y;
				s[i] = 'C';
			}
		}
	}

	return cost;
}

long long int complex_method(short int x, short int y, char *s)
{
	short unsigned int i, j, n = strlen(s);
	long long int cost = 0, tmpCostJ, tmpCostC;

	for (i = 0; i < n; ++i) {
		if (i > 0 && s[i] != '?') {
			cost += (s[i - 1] == 'C' && s[i] == 'J')*x + (s[i - 1] == 'J' && s[i] == 'C')*y;
		} else if (i == 0 && s[i] == '?') {
			for (j = 1; j < n; ++j) {
				if (s[j] != '?') {
					s[0] = s[j];
					break;
				}
			}
		} else if (s[i] == '?') {
			tmpCostJ = tmpCostC = 0;
			tmpCostJ += (i > 0 && s[i - 1] == 'C')*x + (i + 1 < n && s[i + 1] == 'C')*y;
			tmpCostC += (i > 0 && s[i - 1] == 'J')*y + (i + 1 < n && s[i + 1] == 'J')*x;

			if (tmpCostJ < tmpCostC) {
				cost += (i > 0 && s[i - 1] == 'C')*x;
				s[i] = 'J';
			} else {
				cost += (i > 0 && s[i - 1] == 'J')*y;
				s[i] = 'C';
			}
		}
	}

	return cost;
}

int main()
{
	short unsigned int t, xx;
	short int x, y;
	long long int cost;
	char s[1001];

	scanf("%hu", &t);
	for (xx = 1; xx <= t; ++xx) {
		scanf("%hd %hd %s", &x, &y, s);
		if (x >= 0 && y >= 0)
			cost = simple_method(x, y, s);
		else
			cost = complex_method(x, y, s);

		printf("Case #%d: %lld\n", xx, cost);
	}


	return 0;
}