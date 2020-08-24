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
int dist[21][21][21][21];
bool visit[21][21];
int num[21][21];


vector<pair<int, int> > path;
vector<int> picked;
bool used[21];
pair<int, int> startPos;

//모든 간선의 길이 측정
void bfs(int y, int x) {
	memset(visit, 0, sizeof(visit));
	memset(num, 0, sizeof(num));
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
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X || arr[ny][nx] == 'x') continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			num[ny][nx] = num[cy][cx] + 1;
			if (arr[ny][nx] == '*') {
				clean++;
				dist[y][x][ny][nx] = num[ny][nx];
			}
			q.push({ ny, nx });
		}
	}
}

void dfs(int toPick) {
	if (toPick == 0) {
		int len = dist[startPos.first][startPos.second][path[picked[0]].first][path[picked[0]].second];
		for (int i = 1; i < picked.size(); i++) {
			int temp = dist[path[picked[i - 1]].first][path[picked[i - 1]].second][path[picked[i]].first][path[picked[i]].second];
			len += temp;
		}
		ret = min(len, ret);
		return;
	}
	for (int i = 0; i < dust; i++) {
		if (!used[i]) {
			used[i] = true;
			picked.push_back(i);
			dfs(toPick - 1);
			picked.pop_back();
			used[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("input/f1.txt", "r", stdin);

	while (true) {

		cin >> X >> Y;
		if (X == 0 && Y == 0) return 0;
		ret = INF;
		path.clear();
		dust = 0;
		clean = 0;

		for (int i = 0; i < Y; i++) {
			cin >> arr[i];
			for (int j = 0; j < X; j++) {
				if (arr[i][j] == '*') {
					dust++;
					path.push_back({ i, j });
				}
				else if (arr[i][j] == 'o') {
					startPos = { i, j };
					arr[i][j] = '.';
				}
			}
		}

		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				for (int a = 0; a < Y; a++) {
					for (int b = 0; b < X; b++) {
						if (i == a && j == b) dist[i][j][a][b] = 0;
						else dist[i][j][a][b] = INF;
					}
				}
			}
		}
		bfs(startPos.first, startPos.second);
		if (clean != dust) {
			cout << -1 << "\n";
			continue;
		}
		for (auto e : path) {
			bfs(e.first, e.second);
		}

		dfs(dust);

		cout << ((ret == INF) ? -1 : ret) << "\n";

	}

	return 0;
}