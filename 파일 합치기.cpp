#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int K;

int main() {

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> K;
		for(int i=0; i<K; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			if (i == 0) sum[i] = cost[i];
			else sum[i] = sum[i - 1] + cost[i];
		}
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				if (i == j) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = INF;
				}
			}
		}
		
		for (int it = 1; it < K; it++) {

			for (int i = 0; i < K; i++) {
				for (int j = i + it; j < K; j++, i++) {
					for (int k = i; k < j; k++) {
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
					}
				}
			}

		}

		cout << dp[0][K-1] << "\n";
	}

	return 0;
}