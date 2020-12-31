#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 51

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int Y, X;
string map[MAX];
int dp[MAX][MAX];
int visit[MAX][MAX];

int search(int y, int x) {
	if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
	if (visit[y][x]) {
		cout << -1;
		exit(0);
	}
	if (map[y][x] == 'H') return 0;
	if (dp[y][x]) return dp[y][x];

	int jump = map[y][x] - '0';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * jump;
		int nx = x + dx[i] * jump;
		visit[y][x] = 1;
		dp[y][x] = max(dp[y][x], search(ny, nx) + 1);
		visit[y][x] = 0;
	}
	return dp[y][x];
}

int main() {

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		cin >> map[i];
	}

	cout << search(0, 0);

	return 0;
}


