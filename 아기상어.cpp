#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 21
#define INF 987654321

int graph[MAX][MAX];
int sharkSize = 2;
int visit[MAX][MAX];

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int N;

int minDist = INF;
int minX = INF;
int minY = INF;

// bfs로 이동한 시간 return
void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visit[y][x] = 0;
	q.push({ y, x });

	while (!q.empty()) {
		auto front = q.front(); q.pop();
		int cy = front.first;
		int cx = front.second;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visit[ny][nx] != -1 || sharkSize < graph[ny][nx]) continue;

			visit[ny][nx] = visit[cy][cx] + 1;

			if (graph[ny][nx] != 0 && graph[ny][nx] < sharkSize) {
				if (visit[ny][nx] < minDist) {
					minDist = visit[ny][nx];
					minY = ny;
					minX = nx;
				}
				else if (visit[ny][nx] == minDist) {
					if (ny < minY) {
						minY = ny;
						minX = nx;
					}
					else if (ny == minY) {
						if (nx < minX) {
							minY = ny;
							minX = nx;
						}
					}
				}
			}
			q.push({ ny, nx });
		}
	}
}
void init() {
	minDist = INF;
	minX = INF;
	minY = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = -1;
		}
	}
}
int main() {

	cin >> N;

	pair<int, int> cur;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				cur = { i, j };
				graph[i][j] = 0;
			}
		}
	}

	int time = 0;
	int eat = 0;

	while (true) {
		init();
		bfs(cur.first, cur.second);

		if (minDist != INF) {
			time += minDist;
			
			eat++;

			if (eat == sharkSize) {
				sharkSize++;
				eat = 0;
			}

			graph[minY][minX] = 0;

			cur = { minY, minX };

		}
		else {
			break;
		}
		
	}
	cout << time << "\n";

	return 0;
}