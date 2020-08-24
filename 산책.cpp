#include <iostream>
#include <vector>
#define MAX 1005
using namespace std;

int Y, X, N;

int arr[MAX][MAX];
int dp[MAX][MAX];
pair<int, int> ret;

//1이면 오른쪽, 0이면 아래쪽으로 이동 후 최종 도착지를 ret에 저장
void dfs(int y, int x) {
	if (y >= Y || x >= X) {
		ret = { y, x };
		return;
	}
	if (arr[y][x] == 1) {
		dfs(y, x + 1);
	}
	else {
		dfs(y + 1, x);
	}
}

int main() {

	scanf("%d %d %d", &Y, &X, &N);
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = N;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (arr[i][j] == 1) {
				dp[i + 1][j] += dp[i][j] / 2;
				dp[i][j + 1] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1;
			}
			else {
				dp[i + 1][j] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1;
				dp[i][j + 1] += dp[i][j] / 2;
			}
		}
	}
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			dp[i][j] %= 2;
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (!dp[i][j]) {
				arr[i][j] = !arr[i][j];
			}
		}
	}

	dfs(0, 0);

	printf("%d %d\n", ret.first + 1, ret.second + 1);

	return 0;
}