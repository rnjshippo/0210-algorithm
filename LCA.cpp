#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50005
#define DEPTH 16
int parent[MAX][DEPTH + 1];
vector<int> graph[MAX];
int visit[MAX];
int depth[MAX];
int N;

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = DEPTH; i >= 0; i--) {
		int diff = depth[b] - depth[a];
		if (diff >= 1<<i) {
			b = parent[b][i];
		}
	}
	if (a == b) return a;
	for (int i = DEPTH; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

void dp() {
	for (int i = 1; i <= DEPTH; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

void dfs(int cur, int d) {
	visit[cur] = true;
	depth[cur] = d;
	for (int i = 0; i < graph[cur].size(); i++) {
		int child = graph[cur][i];
		if (!visit[child]) {
			parent[child][0] = cur;
			dfs(child, d + 1);
		}
	}
}

int main() {

	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);
	dp();
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}


	return 0;
}