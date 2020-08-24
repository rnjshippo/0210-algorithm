#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 200005

int dp[MAX][3];
int T;
int n;

int main() {

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= 2; j++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &dp[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] += max(dp[i - 1][0], dp[i - 1][1]);
		}
		printf("%d\n", max(dp[n][2], max(dp[n][0], dp[n][1])));

	}

	return 0;
}