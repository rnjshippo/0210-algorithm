#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int n; //��������
int m; //����

int a, b, c;

int graph[101][101];
int cost[101][101];

int main() {

	scanf("%d %d", &n, &m);
	//�ڱ��ڽ����� ���� ��δ� 0���� �ʱ�ȭ�ϰ�
	//�� �ܿ��� INF�� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cost[i][j] = INF;
		}
	}
	//input�� �ް� INF���� ���� ���� ������ ����
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c < cost[a][b] ? c : cost[a][b];
	}


	//�÷��̵�
	//k�� ������ i�� �����, j�� ������
	//i->j ���� i->k->j�� �� �����ٸ� �� ������ �������ִ� ����
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cost[i][k] + cost[k][j] < cost[i][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF) printf("%d ", 0);
			else printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

	return 0;
}