#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define MAX_DEPTH 20
using namespace std;

int N, M;
int parent[MAXN][MAX_DEPTH + 1];
bool visit[MAXN];
int depth[MAXN];
vector<vector<int>> graph;

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = MAX_DEPTH; i >= 0; i--) {
		int diff = depth[b] - depth[a]; //a를 작은 값으로 지정한 경우
		//diff가 루프 안에서 갱신되야함.
		if (diff >= (1 << i)) {
			b = parent[b][i];
		}
	}
	if (a == b) return a;
	//이렇게 하면 최소 공통 조상 바로 밑까지 올라감
	for (int i = MAX_DEPTH; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

void dp() {
	//i / j 위치 주의!!!
	//2^j번째 부모정보를 dp를 이용하여 저장
	for (int j = 1; j <= MAX_DEPTH; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

void dfs(int cur, int d) {
	visit[cur] = true;
	depth[cur] = d;
	for (int j = 0; j < graph[cur].size(); j++) {
		int target = graph[cur][j];
		if (!visit[target]) {
			parent[target][0] = cur;
			dfs(target, d + 1);
		}
	}
}
int main() {

	scanf("%d", &N);
	graph.resize(N + 5);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);
	dp();

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b)); 
	}


	return 0;
}