#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Y, X;
int visit[101][101];
int map[101][101];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push({y, x});
	visit[y][x] = 0;
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		int cy = front.first;
		int cx = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;

			int value = map[ny][nx] ? 1 : 0;
			if (visit[ny][nx] != -1) { //갱신 작업
				if (visit[ny][nx] > visit[cy][cx] + value) {
					visit[ny][nx] = visit[cy][cx] + value;
					q.push({ ny, nx });
				}
				continue;
			}
			visit[ny][nx] = visit[cy][cx] + value;
			q.push({ ny, nx });
		}
	}
}

int main() {

	cin >> X >> Y;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs(0, 0);
	printf("%d\n", visit[Y - 1][X - 1]);

	return 0;
}