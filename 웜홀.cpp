#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

/* 이 문제는 시작점을 1로 고려하지 않음 */

struct edge {
	int from;
	int to;
	int cost;
};

int d[505];
vector<edge> list;

int N, M, W;
int S, E, T;
bool bellmanFord() {
	bool cycle = false;

	for (int iter = 1; iter <= N; iter++) {
		for (int i = 0; i < list.size(); i++) {
			if (d[list[i].to] > d[list[i].from] + list[i].cost) {
				//이 문제는 모든 구간에서의 음의 사이클 여부를 체크해야되므로 무한대여도 체크한다.
				d[list[i].to] = d[list[i].from] + list[i].cost;
				if (iter == N) cycle = true;
			}
		}
	}
	if (cycle) return false;

	return true;
}

int main() {

	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		scanf("%d %d %d", &N, &M, &W);
		list.clear();
		for (int j = 0; j < M; j++) {
			scanf("%d %d %d", &S, &E, &T);
			list.push_back({ S, E, T });
			list.push_back({ E, S, T });
		}
		for (int j = 0; j < W; j++) {
			scanf("%d %d %d", &S, &E, &T);
			list.push_back({ S, E, -T });
		}
		d[1] = 0;
		for (int i = 2; i <= N; i++) {
			d[i] = INF;
		}
		if (bellmanFord()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}



	return 0;
}