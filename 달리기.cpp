#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
#define INF 98765431
string arr[MAX];

int Y, X, K;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int ret = INF;
int visit[MAX][MAX];

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push({ y, x });
	visit[y][x] = 0;
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		int cy = front.first;
		int cx = front.second;
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k <= K; k++) {
				int ny = cy + dy[i] * k;
				int nx = cx + dx[i] * k;
				if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
				if (arr[ny][nx] == '#') break; //뛸 수 있는만큼 뛰고 벽 만나면 그 이상은 못 뛰니깐 break
				if (visit[ny][nx] == -1) {
					visit[ny][nx] = visit[cy][cx] + 1;
					q.push({ ny, nx });
				}
				else if (visit[ny][nx] < visit[cy][cx] + 1) break; //이전에 더 빠르게 도착했다면 생략
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> Y >> X >> K;
	for (int i = 0; i < Y; i++) {
		cin >> arr[i];
	}
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;
	y1 -= 1; x1 -= 1; y2 -= 1; x2 -= 1;
	memset(visit, -1, sizeof(visit));
	bfs(y1, x1);

	cout << visit[y2][x2] << '\n';
	return 0;
}