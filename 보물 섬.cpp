#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int visit[51][51];
string arr[51];

int Y, X;
int type[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int max_len = 0;

void bfs(int y, int x) {
	int len = 0;
	queue<pair<int, int> > q;
	q.push({ y, x });
	visit[y][x] = true;
	int dy, dx, ty, tx;
	arr[y][x] = 0;
	while (!q.empty()) {
		auto front = q.front();
		ty = front.first;
		tx = front.second;
		q.pop();
		len = max(len, visit[ty][tx]);
		for (int i = 0; i < 4; i++) {
			dy = ty + type[i][0];
			dx = tx + type[i][1];
			if (dy < 0 || dy >= Y || dx < 0 || dx >= X) continue;
			if (arr[dy][dx] == 'W') continue;
			if (visit[dy][dx]) continue;
			visit[dy][dx] = visit[ty][tx] + 1;
			q.push({ dy, dx });
		}
	}
	max_len = max(max_len, len - 1);
}

void print() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	cout << '\n';
}

int main() {

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (arr[i][j] == 'L') {
				//cout << i << "," << j << "\n";
				bfs(i, j);
				//print();
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	cout << max_len << '\n';
	return 0;
}