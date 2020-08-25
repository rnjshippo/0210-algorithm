#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 1001
using namespace std;
int dp[MAX][MAX]; //dp[clip][view]

int main() {
	
	int s;
	cin >> s;

	for (int v = 0; v < MAX; v++) {
		for (int c = 0; c < MAX; c++) {
			dp[c][v] = INF;
		}
	}

	dp[0][1] = 0; // base
	dp[1][1] = 1;

	for (int c = 1; c < MAX ; c++) {
		for (int v = 1; v < MAX; v++) {

			if(v + c < MAX) dp[c][v + c] = min(dp[c][v] + 1, dp[c][v + c]);
			dp[v][v] = min(dp[c][v] + 1, dp[v][v]);
		}
		for (int v = MAX - 1; v >= 1; v--) {
			int del = dp[c][v] + 1;
			dp[c][v - 1] = min(del, dp[c][v - 1]);

			if (v + c < MAX) dp[c][v + c] = min(dp[c][v] + 1, dp[c][v + c]);
			dp[v][v] = min(dp[c][v] + 1, dp[v][v]);
		}
	}

	
	int min_val = INF;
	
	for (int c = 0; c < MAX; c++) {
		min_val = min(min_val, dp[c][s]);
	}

	cout << min_val << "\n";
	return 0;
}