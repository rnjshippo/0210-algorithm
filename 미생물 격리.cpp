#include <iostream>
#include <vector>
using namespace std;
#define top 1
#define bottom 2
#define left 3
#define right 4
#define MAX 101

// ������ ���� ���� ���� �� ��������, ū ������ �̵��������� ����
// ���� ���� �����ϸ� �ο� / 2, ������ �ݴ��

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
			if (cur.count == 0) { // ���� �����̳� ���ڰ� 0�̸� ���
				continue;
			}
			
			int ny = cur.y + dy[cur.dir];
			int nx = cur.x + dx[cur.dir];

			auto& next = arr[ny][nx];
			if (next == -1) { // �ش� ������ �������� ���� ��
				next = i;
				if (ny == N - 1 || ny == 0 || nx == N - 1 || nx == 0) { // �����ڸ� ��
					cur.dir = getOpposite(cur.dir);
					cur.count /= 2;
					cur.sum = cur.count;
				}
			}
			else { // �ش� ������ �ٸ� ������ ���� �� :: �� ��쿣 �����ڸ����� ���� �� ����
				if (next < i) { // �� ������ �̵��� ������ ���(������ ���ڰ� ���� ���)
					if (list[next].count < cur.count) { // ���� �� ū ���, �ش� ������ �Դ´�
						cur.sum += list[next].sum; // �ӽ� �κ���

						// ��� ���� ����
						list[next].sum = 0;
						list[next].count = 0;

						next = i; // ���� �ڸ� ����
					}
					else { // ���� �� ������, �� ������ ������
						list[next].sum += cur.sum;

						// �� ���� ����
						cur.count = 0;
						cur.sum = 0;
					}
					
				}
				else { // ���� �̵����� ���� ������ ��� :: �����Ѵ�
					next = i;
					if (ny == N - 1 || ny == 0 || nx == N - 1 || nx == 0) { // �����ڸ� ��
						cur.dir = getOpposite(cur.dir);
						cur.count /= 2;
						cur.sum = cur.count;
					}
				}
			}
			if (arr[cur.y][cur.x] >= i) { // ���� �ڸ��� ������ ū ���� �ִ°��
				arr[cur.y][cur.x] = -1; // ���� �ڸ��� -1 �� ����
			}
			cur.y = ny; // �̵� �� ��ǥ�� ����
			cur.x = nx; // �̵� �� ��ǥ�� ����

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