#include <iostream>
#define INF 987654321
using namespace std;

int list[100002];
int N, S;
int front = -1;
int back = -1;
int part_sum;

int min_len = INF;


void search() {
	while (true) {
		if (part_sum < S) { // ����
			if (back < N - 1) {
				back++;
				part_sum += list[back];
				continue;
			}
			break;
		}
		else if (part_sum > S) { // �ʰ�
			if (back - front < min_len) {
				min_len = back - front;
			}
			if (front < back) {
				front++;
				part_sum -= list[front];
				continue;
			}
			break;
		}
		else { // ��ġ
			if (back - front < min_len) {
				min_len = back - front;
			}
			if (back < N - 1) {
				back++;
				part_sum += list[back];
				continue;
			}
			break;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	search();
	int ret = min_len == INF ? 0 : min_len;
	cout << ret;

	return 0;
}