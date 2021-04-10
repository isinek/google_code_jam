#include <bits/stdc++.h>

#define dump(...)		cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl
#define vec_pair_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << "(" << it->first << " " << it->second << ")" << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

void solution()
{
	unsigned int n, q, s, best_i = 0;
	char *a, ma[130] = {0, };
	unsigned long long prob[3][130] = {0, }, ms = 1, mw = 0, best_s = 0;

	scanf("%u %u", &n, &q);
	mw = (unsigned long long) pow(q, q);
	for (int i = 0; i < n; ++i) {
		a = new char[130];
		*a = {0, };
		scanf("%s %d", a, &s);
		if (s > best_s || q - s > best_s) {
			best_s = (s > (q - s))*s + (s <= (q - s))*(q - s);
			best_i = i;
		}
		for (int j = 0; j < q; ++j) {
			if (!i)
				prob[0][j] = prob[1][j] = 1;

			prob[0][j] *= (a[j] == 'F')*s + (a[j] == 'T')*(q - s);
			prob[1][j] *= (a[j] == 'T')*s + (a[j] == 'F')*(q - s);
		}
	}

	for (int i = 0; i < q; ++i) {
		prob[2][i] = (prob[0][i] >= prob[1][i])*prob[0][i] + (prob[0][i] < prob[1][i])*prob[1][i];
		ms *= prob[2][i];
		ma[i] = (prob[0][i] > prob[1][i])*'F' + (prob[0][i] <= prob[1][i])*'T';
	}

	printf("%s %llu/%u\n", ma, best_s, 1);

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
