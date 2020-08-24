#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N; //���� (����)
int M; //���� (����)
int A, B, C;

const int INF = 987654321;
long long weight[505];
vector<vector<pair<int, int>>> graph; //index = from, first = to, second = cost

bool search() {

	bool cycle = false;
	
	for (int i = 1; i <= N; i++) { //�ݺ� Ƚ�� : �켱 N-1�� �ݺ�, N��°���� ���� ���ϴ����� üũ(���ϸ� ���� ����Ŭ �����ϴ� ��)
		for (int j = 1; j <= N; j++) { //j : ���� ����(��� ���� Ȯ��)
			for (int k = 0; k < graph[j].size(); k++) { //j->k�� ���� ��� Ž��
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
			//		// �湮���� ���� �������� ����� SKIP
			//		if (weight[j] != INF && weight[n.first] > n.second + weight[j]) {
			//			weight[n.first] = n.second + weight[j];
			//			if (i == N) cycle = true;
			//		}
			//	}
			//}

		}
		if (cycle && i == N) return false;
		////N��° ������ �� ���� ������ �ִٸ� ���� ����Ŭ�� �ִ� ��


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