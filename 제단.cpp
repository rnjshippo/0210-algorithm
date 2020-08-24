#include <iostream>
using namespace std;
#define MAX 10005
#define mod 1000000007
typedef long long ll;

int n;
ll h[MAX];
ll dp[2][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	if (n == 1) {
		if(h[0] == -1 || h[0] == 0) cout << 1 << "\n";
		else cout << 0 << "\n";
		return 0;
	}

	dp[0][0] = 1;
	int prev, cur;
	for (int i = 0; i < n; i++) {
		if (i == 0) continue;
		cur = i % 2;
		prev = (i + 1) % 2;
		for (int a = 0; a < MAX; a++) {
			dp[cur][a] = 0;
		}
		if (h[i] == -1) {
			for (int j = 0; j < MAX - 1; j++) {
				if (j - 1 >= 0) dp[cur][j] = (dp[cur][j] + dp[prev][j - 1]) % mod;
				dp[cur][j] = (dp[cur][j] + dp[prev][j]) % mod;
				dp[cur][j] = (dp[cur][j] + dp[prev][j + 1]) % mod;
			}
		}
		else {
			if (h[i] - 1 >= 0) dp[cur][h[i]] = (dp[cur][h[i]] + dp[prev][h[i] - 1]) % mod;
			if (h[i] + 1 < MAX) dp[cur][h[i]] = (dp[cur][h[i]] + dp[prev][h[i] + 1]) % mod;
			dp[cur][h[i]] = (dp[cur][h[i]] + dp[prev][h[i]]) % mod;
		}
		if (i == n - 1) cout << dp[cur][0] % mod << "\n";
	}


	return 0;
}