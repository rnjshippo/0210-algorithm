#include <iostream>
typedef long long ll;
ll dp[91];

int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[n]);
	return 0;
}