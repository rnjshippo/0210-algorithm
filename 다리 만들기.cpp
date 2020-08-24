#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

int arr[101][101];
bool visit[101][101];
int color = 0;
vector<pair<int, int>> outside; //바다에 인접한 지점
vector<pair<int, int>> pick;
bool used[100001];

int type[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; //4방향
int ret = 987654321;

//두 좌표간 거리
int distance(int a1, int b1, int a2, int b2) {
	return abs((a1 - a2)) + abs((b1 - b2)) - 1;
}
//바깥 라인 좌표의 조합
void combination(int idx, int toPick) {
	int y1, x1, y2, x2;
	if (toPick == 0) {
		for (int i = 0; i < pick.size(); i++) {
			if (i == 0) {
				y1 = pick[i].first;
				x1 = pick[i].second;
				continue;
			}
			y2 = pick[i].first;
			x2 = pick[i].second;
		}
		if (arr[y1][x1] != arr[y2][x2]) {
			ret = min(ret, distance(y1, x1, y2, x2));
		}
		return;
	}
	for (int i = idx; i < outside.size(); i++) {
		if (!used[i]) {
			used[i] = true;
			pick.push_back(outside[i]);
			combination(i, toPick - 1);
			used[i] = false;
			pick.pop_back();
		}
	}
}
//섬 구분해서 번호 지정
void bfs(int y, int x) {
	if (visit[y][x]) return;
	if (!arr[y][x]) return;
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;
	int ty, tx, dy, dx;
	color++;
	arr[y][x] = color;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		ty = front.first;
		tx = front.second;
		for (int i = 0; i < 4; i++) {
			dy = ty + type[i][0];
			dx = tx + type[i][1];
			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
			if (arr[dy][dx] == 0) {
				outside.push_back({ ty, tx });
				continue;
			}
			if (visit[dy][dx]) continue;
			visit[dy][dx] = true;
			arr[dy][dx] = color;
			q.push({ dy, dx });
		}
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bfs(i, j);
		}
	}

	sort(outside.begin(), outside.end());
	outside.erase(unique(outside.begin(), outside.end()), outside.end());
	combination(0, 2);
	printf("%d\n", ret);
	return 0;
}