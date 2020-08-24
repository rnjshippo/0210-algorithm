#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int Y, X;

int list[101][101];
bool visit[101][101];
int type[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<pair<int, int>> out;

int cheeze;
int ret;

void bfs(int y, int x) {
	out.clear();
	queue<pair<int, int>> q;
	q.push({ y, x });
	int dy, dx, ty, tx;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		ty = front.first;
		tx = front.second;
		visit[ty][tx] = true;

		for (int i = 0; i < 4; i++) {
			dy = ty + type[i][0];
			dx = tx + type[i][1];
			if (dy < 0 || dy >= Y || dx < 0 || dx >= X) continue;
			if (list[dy][dx]) {
				out.push_back({ dy, dx });
				continue;
			}
			if (visit[dy][dx]) continue;
			q.push({dy, dx});
			visit[dy][dx] = true;
		}
	}
}
void melt() {
	sort(out.begin(), out.end());
	out.erase(unique(out.begin(), out.end()), out.end());
	if (out.size() == cheeze) {
		ret = cheeze;
	}
	for (int i = 0; i < out.size(); i++) {
		auto o = out[i];
		list[o.first][o.second] = 0;
	}
	cheeze -= out.size();
}
void hour() {
	memset(visit, 0, sizeof(visit));
	bfs(0, 0);
	melt();
}


void print() {
	printf("\n");
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			printf("%d ", list[i][j]);
		}
		printf("\n");
	}
}
int main() {

	scanf("%d %d", &Y, &X);
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%d", &list[i][j]);
			if (list[i][j]) cheeze++;
		}
	}
	int sec = 0;
	while (cheeze > 0) {
		hour();
		sec++;
	}
	printf("%d\n", sec);
	printf("%d\n", ret);
	
	return 0;
}