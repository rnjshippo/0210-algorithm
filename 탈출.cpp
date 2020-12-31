#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 51
#define EMPTY '.'
#define WATER '*'
#define STONE 'X'
#define BEAVER 'D'

int Y, X;
string map[MAX];
queue<pair<int, int> > water;
queue<pair<int, int> > hedgehog;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int time = 0;

void flood() {
	int it = water.size();
	for (int i = 0; i < it; i++) {
		auto front = water.front(); 
		water.pop();
		int y = front.first;
		int x = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
			auto& next = map[ny][nx];
			if (next == STONE || next == BEAVER || next == WATER) continue; // 돌, 비버, 물
			next = WATER;
			water.push({ ny, nx });
		}
	}
}

void move() {
	int it = hedgehog.size();
	for (int i = 0; i < it; i++) {
		auto front = hedgehog.front();
		hedgehog.pop();
		int y = front.first;
		int x = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;
			auto& next = map[ny][nx];
			if (next == STONE || next == WATER || next == 'S') continue; // 돌, 물, 고슴도치
			if (next == BEAVER) {
				cout << time;
				exit(0);
			}
			next = 'S';
			hedgehog.push({ ny, nx });
		}
	}
}

int main() {

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		cin >> map[i];
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == WATER) {
				water.push({ i, j });
				continue;
			}
			if (map[i][j] == 'S') {
				hedgehog.push({ i, j });
			}
		}
	}

	while (true) {
		time++;
		flood();
		move();
		if (hedgehog.size() == 0) {
			cout << "KAKTUS";
			break;
		}
	}

	return 0;
}