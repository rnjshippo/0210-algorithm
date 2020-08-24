#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 17

int wait[MAX + 1];
int profit[MAX + 1];
int dp[MAX + 1];

int main() {

	int N;
	int maxProfit = 0;
	cin >> N;
	int t, p; // time, profit
	for (int i = 1; i <= N; i++) {
		cin >> t >> p;
		wait[i] = t;
		profit[i] = (wait[i] + i) <= N + 1 ? p : 0;
		dp[i] = profit[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (wait[j] + j <= i) {
				dp[i] = max(dp[i], profit[i] + dp[j]);
			}
		}
		maxProfit = max(maxProfit, dp[i]);
	}

	maxProfit = max(maxProfit, dp[1]);

	cout << maxProfit;

	return 0;
}