#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FINAL_RES	157

int main()
{
	short unsigned int t, p, x, s, i;
	char qs[10001];
	long long unsigned trivia[100][158] = {{0, }, };
	double students[100] = {0, };
	double q_success[10000] = {0, };
	double tmp_prob;
	long long unsigned tmp_ans;

	scanf("%hu %hu", &t, &p);

	for (x = 1; x <= t; ++x) {
		for (s = 0; s < 100; ++s) {
			scanf("%s", qs);
			students[s] = 3.;
			for (i = 0; i < 10000; ++i) {
				tmp_ans = qs[i] == '1';
				trivia[s][i/64] |= tmp_ans << (i % 64);
				q_success[i] += tmp_ans;
			}
			trivia[s][FINAL_RES] = 0;
		}
		for (i = 0; i < 10000; ++i) {
			q_success[i] = 3. - (q_success[i]/100.)*6.;
			for (s = 0; s < 100; ++s) {
				tmp_ans = ((trivia[s][i/64] >> (i % 64))%2);
				students[s] = (tmp_ans && students[s] < q_success[i])*((students[s] + q_success[i])/2.) + (!tmp_ans && students[s] > q_success[i])*((students[s] + q_success[i])/2.);
			}
		}
		for (i = 0; i < 10000; ++i) {
			for (s = 0; s < 100; ++s) {
				students[s] = 3. - students[s];
				tmp_ans = (trivia[s][i/64] >> (i % 64))%2;
				tmp_prob = 1./(1. + exp(students[s] - q_success[i]));
				trivia[s][FINAL_RES] += (tmp_prob < .5) && tmp_ans;
			}
		}

		s = 0;
		for (i = 1; i < 100; ++i) {
			s = (trivia[s][FINAL_RES] < trivia[i][FINAL_RES])*i + (trivia[s][FINAL_RES] > trivia[i][FINAL_RES])*s;
			printf("%llu %llu\n", trivia[i][FINAL_RES], trivia[s][FINAL_RES]);
		}

		printf("Case #%d: %u\n", x, s + 1);
	}

	return 0;
}
