#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int parent[100];
int Y, X;
int arr[12][12];
bool visit[12][12];
int color;
int type[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<pair<int, int>> outside;
vector<pair<int, pair<int, int>>> bridge; //val, y, x

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	parent[rootB] = rootA;
}

void findBridge() {
	int size = outside.size();
	int from, to;
	int dy, dx, ty, tx;
	int len = 0;
	for (int i = 0; i < size; i++) {
		ty = outside[i].first;
		tx = outside[i].second;
		from = arr[ty][tx];
		for (int j = 0; j < 4; j++) {
			len = 0;
			dy = ty + type[j][0];
			dx = tx + type[j][1];
			to = -1;
			while (true) {
				if (dy < 0 || dy >= Y || dx < 0 || dx >= X) break;
				if (arr[dy][dx]) {
					to = arr[dy][dx];
					break;
				}
				len++;
				dy += type[j][0];
				dx += type[j][1];
			}
			if (len > 1 && from != to && to != -1) {
				if (from < to) {
					bridge.push_back({ len, {from, to} });
				}
				else {
					bridge.push_back({ len, {to, from} });
				}

			}

		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	int dy, dx, ty, tx;
	color++;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		ty = front.first;
		tx = front.second;
		visit[ty][tx] = true;
		arr[ty][tx] = color;
		for (int i = 0; i < 4; i++) {
			dy = ty + type[i][0];
			dx = tx + type[i][1];
			if (dy < 0 || dy >= Y || dx < 0 || dx >= X) continue;
			if (arr[dy][dx] == 0) {
				outside.push_back({ ty, tx });
				continue;
			}
			if (visit[dy][dx]) continue;
			q.push({ dy, dx });
		}
	}
}

int main() {

	scanf("%d %d", &Y, &X);
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (arr[i][j] && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}

	sort(outside.begin(), outside.end());
	outside.erase(unique(outside.begin(), outside.end()), outside.end());

	findBridge();
	sort(bridge.begin(), bridge.end());
	bridge.erase(unique(bridge.begin(), bridge.end()), bridge.end());

	int cost = 0;
	for (int i = 1; i < 100; i++) {
		parent[i] = i;
	}
	vector<int> list;
	for (int i = 0; i < bridge.size(); i++) {
		int from = bridge[i].second.first;
		int to = bridge[i].second.second;
		if (find(from) != find(to)) {
			merge(from, to);
			cost += bridge[i].first;
			list.push_back(i);
		}
	}
	bool exist = true;

	int pa = -1;
	for (int i = 1; i <= color; i++) {
		if (i == 1) {
			pa = find(i);
			continue;
		}
		if (pa != find(i)) {
			exist = false;
			break;
		}
	}


	if (exist) {
		printf("%d\n", cost);
	}
	else {
		printf("%d\n", -1);
	}


	return 0;
}