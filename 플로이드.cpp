#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int n; //버스정점
int m; //간선

int a, b, c;

int graph[101][101];
int cost[101][101];

int main() {

	scanf("%d %d", &n, &m);
	//자기자신한테 가는 경로는 0으로 초기화하고
	//그 외에는 INF로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cost[i][j] = INF;
		}
	}
	//input를 받고 INF보다 작은 값이 들어오면 수정
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = c < cost[a][b] ? c : cost[a][b];
	}


	//플로이드
	//k는 경유지 i는 출발지, j는 도착지
	//i->j 보다 i->k->j가 더 가깝다면 그 값으로 변경해주는 과정
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