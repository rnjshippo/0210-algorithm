#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 10000

int indegree[MAX];
bool used[MAX];
int max_idx;

int main() {
	int a, b;
	int t = 0;
	int cnt = 0;
	int line = 0;
	while (true) {
		scanf("%d %d", &a, &b);
		cnt++;
		if (a == 0 && b == 0) {
			cnt--;
			t++;
			if (cnt == 0) {
				printf("Case %d is a tree.\n", t);
				continue;
			}
			bool tree = true;
			int node = 0;
			//indegree 1���� ū �� �ִ��� Ȯ��
			for (int i = 1; i <= max_idx; i++) {
				if (used[i]) {
					node++;
					if (indegree[i] > 1) {
						tree = false;
						break;
					}
				}
			}

			//��Ʈ ��� ã��, ������ ���� 0
			int root = 0;
			for (int i = 1; i <= max_idx; i++) {
				if (used[i]) {
					if (indegree[i] == 0) {
						root++;
					}
				}
			}
			//��Ʈ�� 1������ Ʈ��
			if (root != 1) {
				tree = false;
			}

			//�ܹ������� üũ ( ���� + 1 = ���)
			if (node != line + 1) {
				tree = false;
			}


			if (tree) {
				printf("Case %d is a tree.\n", t);
			}
			else {
				printf("Case %d is not a tree.\n", t);
			}

			memset(used, 0, sizeof(used));
			memset(indegree, 0, sizeof(indegree));
			line = max_idx = cnt = 0;
		}
		else {
			indegree[b]++;
			used[a] = used[b] = true;
			max_idx = max(a, max_idx);
			max_idx = max(b, max_idx);
			line++;
		}

		if (a < 0 && b < 0) {
			break;
		}
	}

	return 0;
}