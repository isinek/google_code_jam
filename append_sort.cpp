#include <bits/stdc++.h>

#define dump(...)	cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)	cerr << "[" << #__VA_ARGS__ ": ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

void solution()
{
	unsigned long long int n, result = 0;
	unsigned short carry;
	char x[150] = {0, }, new_x[150] = {0, }, prev_x[150] = {0, };
	scanf("%llu", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", x);

		if (!i) {
			strcpy(prev_x, x);
			continue;
		}

		strcpy(new_x, x);
		if (strlen(x) <= strlen(prev_x) && strncmp(x, prev_x, strlen(x)) < 0) {
			for (int j = strlen(x); j <= strlen(prev_x); ++j)
				strcat(new_x, "0");
		} else if (strlen(x) <= strlen(prev_x) && strncmp(x, prev_x, strlen(x)) == 0) {
			strcat(new_x, prev_x + strlen(x));
			carry = 1;
			for (int j = strlen(prev_x) - 1; j >= strlen(x) && carry; --j) {
				--carry;
				if (++new_x[j] > '9') {
					new_x[j] = '0';
					++carry;
				}
			}
			if (carry)
				strcat(new_x, "0");
		} else {
			for (int j = strlen(x); j < strlen(prev_x); ++j)
				strcat(new_x, "0");
		}

		result += strlen(new_x) - strlen(x);
		strcpy(prev_x, new_x);
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
