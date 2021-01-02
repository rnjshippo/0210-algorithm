#include <iostream>
using namespace std;
#define MAX 10002

int front = -1;
int back = -1;
int list[MAX];
int N, M;
int cnt;
int part_sum;

void search() {

	while (true) {

		if (part_sum < M) { // ����
			if(back < N - 1){
				back++;
				part_sum += list[back];
				continue;
			}
			break;
		}
		else if (part_sum > M) { // �ʰ�
			if (front < back) {
				front++;
				part_sum -= list[front];
				continue;
			}
			break;
		}
		else { // ��ġ
			cnt++;
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

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	search();

	cout << cnt;

	return 0;
}