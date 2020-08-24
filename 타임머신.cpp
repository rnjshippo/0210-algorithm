#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N; //도시 (정점)
int M; //버스 (간선)
int A, B, C;

const int INF = 987654321;
long long weight[505];
vector<vector<pair<int, int>>> graph; //index = from, first = to, second = cost

bool search() {

	bool cycle = false;
	
	for (int i = 1; i <= N; i++) { //반복 횟수 : 우선 N-1번 반복, N번째에는 값이 변하는지만 체크(변하면 음의 사이클 존재하는 것)
		for (int j = 1; j <= N; j++) { //j : 시작 정점(모든 정점 확인)
			for (int k = 0; k < graph[j].size(); k++) { //j->k로 가는 경로 탐색
				auto target = graph[j][k];
				int t_vertex = target.first;
				int t_cost = target.second;
				if (weight[j] != INF && (weight[t_vertex] > (weight[j] + t_cost))) {
					weight[t_vertex] = (weight[j] + t_cost);
					if (i == N) cycle = true;
				}
			}
			//for (int j = 1; j <= N; j++) {
			//	for (auto &n : graph[j]) {
			//		// 방문되지 않은 지점에서 출발은 SKIP
			//		if (weight[j] != INF && weight[n.first] > n.second + weight[j]) {
			//			weight[n.first] = n.second + weight[j];
			//			if (i == N) cycle = true;
			//		}
			//	}
			//}

		}
		if (cycle && i == N) return false;
		////N번째 수행한 후 값의 변동이 있다면 음의 사이클이 있는 것


	}

	return true;
}

int main() {

	scanf("%d %d", &N, &M);
	graph.resize(N + 5);
	for (int i = 2; i <= N; i++) {
		weight[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		graph[A].push_back({ B, C });
	}

	if (search()) {
		for (int i = 2; i <= N; i++) {
			if (weight[i] == INF) printf("%d\n", -1);
			else printf("%d\n", weight[i]);
		}
	}
	else {
		printf("%d\n", -1);
	}




	return 0;
}