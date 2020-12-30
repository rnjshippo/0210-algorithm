#include <iostream>
using namespace std;
#define MAX 502

int arr[MAX][MAX];
int dp[MAX][MAX];
int Y, X;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
	if (y == Y - 1 && x == X - 1) {
		return 1;
	}
	
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
		if (arr[ny][nx] >= arr[y][x]) continue;
		dp[y][x] += dfs(ny, nx);
		
	}
	return dp[y][x];
}

int main() {

	cin >> Y >> X;
	
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	
	cout << dfs(0, 0);

	return 0;
}

/*
4 4
16 9 8 1
15 10 7 2
14 11 6 3
13 12 5 4
*/