#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X, Y, H;
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int box[101][101][101];
struct Box {
	int y;
	int x;
	int h;
};
queue<Box> q;

void print(int box[][101][101]) {
	printf("\n");
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				printf("%d ", box[i][j][k]);
			}
			printf("\n");
		}
	}
}


void go() {

	while (!q.empty()) {
		//print(box);
		int i = q.front().y;
		int j = q.front().x;
		int k = q.front().h;
		q.pop();
		for (int a = 0; a < 6; a++) {
			int cy = i + dy[a];
			int cx = j + dx[a];
			int cz = k + dz[a];
			if (cy < 0 || cy >= Y || cx < 0 || cx >= X || cz < 0 || cz >= H) continue;
			if (box[cy][cx][cz] == 0) {
				box[cy][cx][cz] = box[i][j][k] + 1;
				q.push({ cy, cx, cz });
			}
		}
	}

}


int main() {

	scanf("%d %d %d", &X, &Y, &H);
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				scanf("%d", &box[i][j][k]);
				if(box[i][j][k] == 1) q.push({ i, j, k });
			}
		}
	}

	go();
	int ret = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (box[i][j][k] == 0) {
					printf("%d\n", -1); //안익은게 있으면 -1
					return 0;
				}
				ret = max(ret, box[i][j][k]);
			}
		}
	}
	printf("%d\n", ret - 1);

	return 0;
}