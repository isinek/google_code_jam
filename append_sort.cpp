#include <bits/stdc++.h>

#define dump(...)	cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)	cerr << "[" << #__VA_ARGS__ ": ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

void solution()
{
	unsigned long long int n, x, prev_x, result = 0;
	long long int len_diff, mult;
	char sx[300] = {0, }, prev_sx[300] = {0, };
	scanf("%llu", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%llu", &x);
		sprintf(sx, "%llu", x);

		if (i > 0) {
			len_diff = strlen(prev_sx) - strlen(sx);
			result += (len_diff > 0)*len_diff;
			mult = (len_diff > 0)*(int)pow(10, len_diff) + (len_diff <= 0)*1;
			x *= mult;
			if (prev_x >= x + mult - 1) {
				x *= 10;
				++result;
			} else if (prev_x >= x) {
				x += (prev_x%mult) + 1;
			}
		}

		prev_x = x;
		sprintf(prev_sx, "%llu", x);
	}

	printf("%llu\n", result);

	return;
}

int main()
{
	unsigned int T;

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%u: ", i);
		solution();
	}
}
