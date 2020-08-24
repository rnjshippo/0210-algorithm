#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int student[32005];
int N, M;
vector<vector<int>> graph;
queue<int> result;
int indegree[32005];

void topol() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0){
			q.push(i);
		}
	}
	while (!q.empty()) {
		int front = q.front();
		result.push(front);
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			int target = graph[front][i];
			if (--indegree[target] == 0) {
				q.push(target);
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);
	graph.resize(N + 5);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		indegree[b]++;
	}
	topol();

	while (!result.empty()) {
		printf("%d ", result.front());
		result.pop();
	}

	return 0;
}