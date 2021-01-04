#include <iostream>
using namespace std;
#define MAX 1025

int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] += dp[i - 1][j];
		}
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << dp[y2][x2] - dp[y2][x1 -1] - (dp[y1 - 1][x2] - dp[y1 - 1][x1 - 1]) << "\n";
	}

	return 0;
}