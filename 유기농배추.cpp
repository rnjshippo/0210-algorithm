#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

bool visit[MAX][MAX];
int map[MAX][MAX];
int cnt;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int X, Y, K;

void reset() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			visit[i][j] = 0;
			map[i][j] = 0;
		}
	}
}

void bfs(int sy, int sx) {
	queue<pair<int, int> > q;
	q.push({ sy, sx });
	visit[sy][sx] = 1;
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		int y = front.first;
		int x = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
			if (visit[ny][nx]) continue;
			if (map[ny][nx] == 0) continue;
			visit[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> X >> Y >> K;
		reset();

		int y, x;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		cnt = 0;
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if(!visit[i][j] && map[i][j] == 1){
					cnt++;
					bfs(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}