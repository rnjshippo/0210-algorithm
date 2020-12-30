#include <iostream>
#include <string>
using namespace std;
#define MAX 22

int Y, X;
string map[MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int max_count;
bool used[27];
bool visit[MAX][MAX];

void dfs(int y, int x, int cnt) {
	visit[y][x] = true;
	used[map[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
		char alpha = map[ny][nx];
		if (!visit[ny][nx] && !used[alpha - 'A']) {
			visit[ny][nx] = true;
			used[alpha - 'A'] = true;
			dfs(ny, nx, cnt + 1);
			visit[ny][nx] = false;
			used[alpha - 'A'] = false;
		}
	}
	if (max_count < cnt) {
		max_count = cnt;
	}
}

int main() {

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		cin >> map[i];
	}

	dfs(0, 0, 1);

	cout << max_count;

	return 0;
}