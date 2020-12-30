#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 102

string map[MAX];
int N;

int visit[MAX][MAX];
int color = 0;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void reset() {
	color = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = -1;
		}
	}
}

void bfs(int sy, int sx, bool normal) {
	color += 1;
	queue<pair<int, int> > q;
	visit[sy][sx] = color;
	q.push({ sy, sx });

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int y = front.first;
		int x = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visit[ny][nx] != -1) continue;
			if (normal) {
				if (map[ny][nx] == map[y][x]) {
					visit[ny][nx] = color;
					q.push({ ny, nx });
				}
			}
			else {
				bool current_is_red_or_green = map[y][x] == 'R' || map[y][x] == 'G';
				bool next_color_is_red_or_green = map[ny][nx] == 'R' || map[ny][nx] == 'G';
				if ( (map[ny][nx] == map[y][x]) || (current_is_red_or_green && next_color_is_red_or_green) ) {
					q.push({ ny,nx });
					visit[ny][nx] = color;
				}
			}

		}
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j];
		}
		cout << "\n";
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	// normal count
	int normal_count = 0;
	int abnormal_count = 0;

	reset();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == -1) {
				bfs(i, j, true);
				normal_count += 1;
			}
		}
	}
	//print();



	reset();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == -1) {
				bfs(i, j, false);
				abnormal_count += 1;
			}
		}
	}
	//print();

	cout << normal_count << " " << abnormal_count;

	return 0;
}