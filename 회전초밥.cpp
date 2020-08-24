#include <iostream>
#define MAX 3000005

int list[MAX];
int count[3005];
int dp[MAX];

int main() {

	int N, d, k, c;
	int maxIdx = -1;
	int maxVal = -1;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}

	for (int i = 0; i < k; i++) {
		if(i > 0) dp[i] = dp[i - 1];
		if (list[i] == c) continue;
		if (count[list[i]] == 0) {
			dp[i]++;
		}
		count[list[i]]++;
		if (maxVal < dp[i]) {
			maxVal = dp[i];
			maxIdx = i;
		}
	}
	int idx = 0;
	for (int i = k; i < N; i++) {
		if (i > 0) dp[i] = dp[i - 1];
		count[list[idx++]]--;
		if (count[list[idx - 1]] == 0) dp[i]--;
		if (list[i] == c) continue;
		if (count[list[i]] == 0) {
			dp[i]++;
		}
		count[list[i]]++;
		if (maxVal < dp[i]) {
			maxVal = dp[i];
			maxIdx = i;
		}
	}
	// 0부터 다시 처리
	idx = N - k;
	for (int i = 0; i < k; i++) {
		if (i == 0) dp[i] = dp[N - 1];
		else dp[i] = dp[i - 1];

		count[list[idx++]]--;
		if (count[list[idx - 1]] == 0) dp[i]--;
		if (list[i] == c) continue;
		if (count[list[i]] == 0) {
			dp[i]++;
		}
		count[list[i]]++;
		if (maxVal < dp[i]) {
			maxVal = dp[i];
			maxIdx = i;
		}
	}

	printf("%d\n", maxVal + 1);
	return 0;
}