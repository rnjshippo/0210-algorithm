#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define INF 987654321

int X, Y;
string arr[21];
int dust;
int clean;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int ret = INF;
bool check[21][21];

int bfs(int y, int x, int len) {
	if (ret < len) {
		return 0;
	}
	if (dust == clean) {
		ret = min(ret, len);
		return 0;
	}
	bool visit[21][21] = { 0, };
	int num[21][21] = { 0, };
	queue<pair<int, int> > q;
	q.push({ y, x });
	visit[y][x] = true;
	
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nx < 0 || nx >= X || ny < 0 || ny >= Y || arr[ny][nx] == 'x') continue; //범위 밖 or 가구
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			num[ny][nx] = num[cy][cx] + 1;

			if (arr[ny][nx] == '*' && !check[ny][nx]) {
				clean++;
				check[ny][nx] = true;
				bfs(ny, nx, len + num[ny][nx]);
				check[ny][nx] = false;
				clean--;
			}
			q.push({ ny, nx });
		}
	}
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	pair<int, int> startPos;

	while (true) {
		ret = INF;
		cin >> X >> Y;
		if (X == 0 && Y == 0) return 0;
		clean = 0;
		dust = 0;
		for (int i = 0; i < Y; i++) {
			cin >> arr[i];
			for (int j = 0; j < X; j++) {
				if (arr[i][j] == '*') dust++;
				else if (arr[i][j] == 'o') {
					startPos = { i, j };
					arr[i][j] = '.';
				}
			}
		}

		bfs(startPos.first, startPos.second, 0);

		cout << ( (ret == INF) ? -1 : ret ) << "\n";

	}

	return 0;
}