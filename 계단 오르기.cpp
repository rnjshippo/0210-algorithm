#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 302

int stair[MAX];
int dp[MAX];
int N;
int visit[MAX];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[2] + dp[1];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2], stair[i - 1] + dp[i - 3]) + stair[i];
	}

	cout << dp[N];

	return 0;
}