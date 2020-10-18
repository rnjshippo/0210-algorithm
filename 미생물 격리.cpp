#include <iostream>
#include <vector>
using namespace std;
#define top 1
#define bottom 2
#define left 3
#define right 4
#define MAX 101

// 군집이 같은 셀에 모일 때 합쳐지고, 큰 군집의 이동방향으로 설정
// 셀의 끝에 도달하면 인원 / 2, 방향을 반대로

struct Info {
	int y;
	int x;
	int count;
	int dir;
	int sum;
};

int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };
int arr[MAX][MAX];
int N, M, K;

int getOpposite(int dir) {
	switch (dir) {
	case top:
		return bottom;
	case bottom:
		return top;
	case left:
		return right;
	case right:
		return left;
	}
}

void resetMap() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = -1;
		}
	}
}

int getAlive(vector<Info>& list) {
	int count = 0;
	for (int i = 0; i < list.size(); i++) {
		count += list[i].count;
	}
	return count;
}

void debug(vector<Info>& list) {
	for (int i = 0; i < list.size(); i++) {
		printf("-- %d %d %d %d   sum : %d\n", list[i].y, list[i].x, list[i].count, list[i].dir, list[i].sum);
	}
}

int simulate(int time, vector<Info>& list) {

	for (int t = 0; t < time; t++) {
		for (int i = 0; i < list.size(); i++) {

			auto& cur = list[i];
			if (cur.count == 0) { // 먹힌 군집이나 숫자가 0이면 통과
				continue;
			}
			
			int ny = cur.y + dy[cur.dir];
			int nx = cur.x + dx[cur.dir];

			auto& next = arr[ny][nx];
			if (next == -1) { // 해당 구역에 존재하지 않을 때
				next = i;
				if (ny == N - 1 || ny == 0 || nx == N - 1 || nx == 0) { // 가장자리 셀
					cur.dir = getOpposite(cur.dir);
					cur.count /= 2;
					cur.sum = cur.count;
				}
			}
			else { // 해당 구역에 다른 군집이 있을 때 :: 이 경우엔 가장자리에서 만날 수 없음
				if (next < i) { // 그 군집이 이동한 군집인 경우(나보다 숫자가 작은 경우)
					if (list[next].count < cur.count) { // 내가 더 큰 경우, 해당 군집을 먹는다
						cur.sum += list[next].sum; // 임시 부분합

						// 상대 군집 삭제
						list[next].sum = 0;
						list[next].count = 0;

						next = i; // 현재 자리 변경
					}
					else { // 내가 더 작으면, 내 군집이 먹힌다
						list[next].sum += cur.sum;

						// 내 군집 삭제
						cur.count = 0;
						cur.sum = 0;
					}
					
				}
				else { // 아직 이동하지 않은 군집인 경우 :: 무시한다
					next = i;
					if (ny == N - 1 || ny == 0 || nx == N - 1 || nx == 0) { // 가장자리 셀
						cur.dir = getOpposite(cur.dir);
						cur.count /= 2;
						cur.sum = cur.count;
					}
				}
			}
			if (arr[cur.y][cur.x] >= i) { // 기존 자리에 나보다 큰 값이 있는경우
				arr[cur.y][cur.x] = -1; // 기존 자리를 -1 로 변경
			}
			cur.y = ny; // 이동 후 좌표로 변경
			cur.x = nx; // 이동 후 좌표로 변경

		}
		for (int i = 0; i < list.size(); i++) {
			auto cur = list[i];
			list[i].count = list[i].sum;
		}
	}

	return getAlive(list);

}



int main() {

	int tc;
	cin >> tc;
	vector<Info> list;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M >> K;

		// reset
		list.clear();
		resetMap();

		for (int i = 0; i < K; i++) {
			int y, x, count, dir;
			cin >> y >> x >> count >> dir;
			list.push_back({ y, x, count, dir, count });
		}

		// start
		int alive = simulate(M, list);

		// print result
		printf("#%d %d\n", t, alive);
	}


	return 0;
}