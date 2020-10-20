#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 51
#define MP 1200

struct Ball {
	int y, x, m, s, d; // y, x, 질량, 속도, 방향
};

int N, M, K;
vector<Ball> b_list;
int arr[MAX][MAX];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void merge_divide(vector<int> arr[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			auto& c = arr[i][j];
			int c_size = c.size();
			if (c_size <= 1) continue;

			int new_mass = 0, new_speed = 0;
			int mass_sum = 0, speed_sum = 0;

			bool odd = true;
			bool even = true;

			for (int k = 0; k < c_size; k++) {
				auto& t = c[k];
				mass_sum += b_list[t].m;
				speed_sum += b_list[t].s;
				b_list[t].m = 0; // 기존 제거
				bool is_even = (b_list[t].d % 2) == 0;
				if (is_even) {
					even = true && even;
					odd = false && odd;
				}
				else {
					even = false && even;
					odd = true && odd;
				}
			}
			new_mass = floor(mass_sum / 5);
			new_speed = floor(speed_sum / c_size);

			int dir;

			if (odd || even) dir = 0; // 0, 2, 4, 6
			else dir = 1; // 1, 3, 5, 7

			for (int a = 0; a < 4; a++) {
				b_list.push_back({ i, j, new_mass, new_speed, dir });
				dir += 2;
			}

		}
	}
}

void move(vector<int> arr[][MAX]) {
	for (int i = 0; i < b_list.size(); i++) {
		auto& c = b_list[i];
		if (c.m <= 0) continue;
		c.y = (c.y + dy[c.d] * c.s + MP) % N;
		c.x = (c.x + dx[c.d] * c.s + MP) % N;
		arr[c.y][c.x].push_back(i);
	}
}

int simulate() {
	int mass_sum = 0;
	for (int i = 0; i < K; i++) {
		vector<int> arr[MAX][MAX];
		move(arr);
		merge_divide(arr);
	}
	for (int i = 0; i < b_list.size(); i++) {
		mass_sum += b_list[i].m;
	}
	return mass_sum;
}


int main() {

	cin >> N >> M >> K;

	int y, x, m, s, d;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> m >> s >> d;
		b_list.push_back({ y - 1, x - 1, m, s, d });
	}


	int mass_sum = simulate();

	cout << mass_sum << "\n";

	return 0;
}