#include <iostream>
using namespace std;
#define MAX 501
bool arr[MAX][MAX];

int main() {

	int Y, X;
	cin >> Y >> X;
	int temp;
	for (int j = 0; j < X; j++) {
		cin >> temp;
		for (int i = 0; i < temp; i++) {
			arr[i][j] = 1;
		}
	}

	int full_count = 0;

	for (int i = 0; i < Y; i++) {
		int count = 0;
		bool start = false;
		for (int j = 0; j < X; j++) {
			if (!start) {
				if (arr[i][j]) {
					start = true;
					continue;
				}
			}

			if (start) {
				if (arr[i][j]) { // ������ ������ ���� ���
					full_count += count;
					count = 0;
					continue;
				}
				if (!arr[i][j]) { // ����ִ� ������ ���
					count += 1;
					continue;
				}
			}

		}
	}

	cout << full_count << "\n";

	return 0;
}