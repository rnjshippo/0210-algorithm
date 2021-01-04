#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 502

int arr[MAX][MAX];
int dp[MAX][MAX];
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j]);
			if (j - 1 >= 0) {
				dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i][j]);
			}
		}
	}

	int ret = -1;

	for (int i = 1; i <= n; i++) {
		ret = max(ret, dp[n][i]);
	}

	cout << ret << "\n";

	return 0;
}