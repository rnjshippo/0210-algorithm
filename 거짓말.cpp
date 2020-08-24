#include <iostream>
#include <vector>
using namespace std;
#define MAX 51
#define real 2
#define lie 1
#define base 0

int N, M, t; // t = ������ �ƴ� ��� ��
int lies[MAX]; // ������ �ƴ��� ����
vector<int> party[MAX];
int cnt;

int main() {

	int temp;
	int num;

	scanf("%d %d %d", &N, &M, &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &temp);
		lies[temp] = real;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &temp);
			party[i].push_back(temp);
		}
	}

	if (t == 0) {
		printf("%d\n", M);
	}
	else {
		for (int a = 0; a < M; a++) {
			for (int i = 0; i < M; i++) {
				bool canLie = true;
				for (int j = 0; j < party[i].size(); j++) {
					if (lies[party[i][j]] == real) {
						canLie = false;
						break;
					}
				}

				if (!canLie) { // ����
					for (int j = 0; j < party[i].size(); j++) {
						lies[party[i][j]] = real;
					}
				}
			}
		}


		for (int i = 0; i < M; i++) {
			bool canLie = true;
			for (int j = 0; j < party[i].size(); j++) {
				if (lies[party[i][j]] == real) {
					canLie = false;
					break;
				}
			}

			if (canLie) { // ����
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}