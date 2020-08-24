#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 100001

int N;
int arr[MAX][3];
int dp[2][3];
int min_dp[2][3];
int type[3][2] = { {-1, -1}, {-1, 0}, {-1, 1} };

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			min_dp[i][j] = INF;
		}
	}

	min_dp[0][0] = dp[0][0] = arr[0][0];
	min_dp[0][1] = dp[0][1] = arr[0][1];
	min_dp[0][2] = dp[0][2] = arr[0][2];

	int next, prev;
	for (int i = 0; i < N; i++) {
		prev = (i + 1) % 2;
		next = i % 2;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int dy = next == 1 ? next + type[k][0] : next - type[k][0];
				int dx = j + type[k][1];
				if (dy < 0 || dy >= N || dx < 0 || dx >= 3) continue;
				dp[next][j] = max(dp[next][j], dp[dy][dx] + arr[i][j]);
				min_dp[next][j] = min(min_dp[next][j], min_dp[dy][dx] + arr[i][j]);
			}
		}
		for (int j = 0; j < 3; j++) {
			min_dp[prev][j] = INF;
			dp[prev][j] = 0;
		}
	}

	printf("%d ", max(dp[next][2], max(dp[next][0], dp[next][1])));
	printf("%d\n", min(min_dp[next][2], min(min_dp[next][0], min_dp[next][1])));

	return 0;
}