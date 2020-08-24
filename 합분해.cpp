#include <iostream>
#define mod 1000000000
typedef long long ll;

int N, K;
ll dp[201][201];

int main() {

	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int k = 1; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int l = 0; l <= n; l++) {
				dp[k][n] = (dp[k][n] % mod + dp[k - 1][n - l] % mod) % mod;
			}
		}
	}
	printf("%lld\n", dp[K][N] % mod);

	return 0;
}