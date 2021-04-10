#include <bits/stdc++.h>

#define dump(...)		cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl
#define arr_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) << "): ["; for (unsigned long long int it = 0; it < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]); ++it) cerr << (__VA_ARGS__)[it] << (it + 1 < sizeof((__VA_ARGS__))/sizeof((__VA_ARGS__)[0]) ? ", " : ""); cerr << "]]" << endl
#define vec_dump(...)		cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << *it << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl
#define pair_dump(...)		cerr << "[" << #__VA_ARGS__ ": (" << it->first << ", " << it->second << ")]" << endl
#define vec_pair_dump(...)	cerr << "[" << #__VA_ARGS__ "(" << (__VA_ARGS__).size() << "): ["; for (auto it = (__VA_ARGS__).begin(); it != (__VA_ARGS__).end(); ++it) cerr << "(" << it->first << ", " << it->second << ")" << (it + 1 != (__VA_ARGS__).end() ? ", " : ""); cerr << "]]" << endl

using namespace std;

unsigned long long search_for_solution(vector < pair < unsigned int, unsigned int > > primes, unsigned int start_index, unsigned long long sum_pile, unsigned long long mult_pile)
{
	unsigned long long best_score = 0, tmp_score;

	for (int i = start_index; i < primes.size(); ++i) {
		if (primes[i].second) {
			--primes[i].second;
			sum_pile -= primes[i].first;
			mult_pile *= primes[i].first;

			if (sum_pile == mult_pile && best_score < mult_pile) {
				best_score = mult_pile;
			} else if (sum_pile > mult_pile) {
				tmp_score = search_for_solution(primes, i, sum_pile, mult_pile);
				best_score = (tmp_score > best_score)*tmp_score + (tmp_score <= best_score)*best_score;
			}

			++primes[i].second;
			sum_pile += primes[i].first;
			mult_pile /= primes[i].first;
		}
	}

	return best_score;
}

void solution()
{
	unsigned int m, n, p;
	vector < pair < unsigned int, unsigned int > > primes;
	unsigned long long sum_pile = 0, mult_pile = 1;

	scanf("%u", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%u %u", &p, &n);
		primes.emplace_back(p, n);

		sum_pile += primes.back().first * primes.back().second;
	}

	mult_pile = search_for_solution(primes, 0, sum_pile, mult_pile);

	printf("%llu\n", mult_pile);

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
