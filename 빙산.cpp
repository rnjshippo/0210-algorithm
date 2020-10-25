#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301
using namespace std;
int Y, X;
int arr[MAX][MAX];
int temp[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1,-1, 0, 0 };
int year = 0;

void melt() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (arr[i][j] == 0) continue;
			int count = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
				if (arr[ny][nx] == 0) count += 1;
			}
			temp[i][j] -= count;
		}
	}
}

void apply() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			arr[i][j] += temp[i][j];
			if (arr[i][j] < 0) arr[i][j] = 0;
			temp[i][j] = 0;
		}
	}
}

int is_divided() {
	int count = 0;
	bool visit[MAX][MAX];
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (arr[i][j] == 0) continue;
			if (visit[i][j]) continue;
			count += 1;
			queue<pair<int, int> > q;
			q.push({ i, j });
			visit[i][j] = true;
			while (!q.empty()) {
				auto front = q.front(); q.pop();
				int y = front.first;
				int x = front.second;

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
					if (arr[ny][nx] == 0) continue;
					if (visit[ny][nx]) continue;
					q.push({ ny, nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
	return count;
}

void debug() {
	cout << "\n";
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> arr[i][j];
		}
	}


	while (true) {
		year += 1;

		memset(visit, 0, sizeof(visit));
		melt();
		apply();

		int count = is_divided();
		if (count > 1) {
			cout << year << "\n";
			return 0;
		}
		if (count == 0) {
			cout << 0 << "\n";
			return 0;
		}
	}

	return 0;
}