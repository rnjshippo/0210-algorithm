#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100005
#define DEPTH 20
#define INF 987654321

int parent[MAX][DEPTH + 1];
int max_val[MAX][DEPTH + 1];
int min_val[MAX][DEPTH + 1];
bool visit[MAX];
int depth[MAX];
vector<pair<int, int>> graph[MAX]; //index : from , first : to, second : value
int N;

//lca ������ �ּ�, �ִ밪�� ����
pair<int, int> lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	int startA = a;
	int startB = b;
	int min_v = INF, max_v = -INF;
	for (int i = DEPTH; i >= 0; i--) {
		int diff = depth[b] - depth[a];
		if (diff >= 1 << i) {
			min_v = min(min_v, min_val[b][i]);
			max_v = max(max_v, max_val[b][i]);
			b = parent[b][i];
		}
	}
	if (a == b) {
		return { min_v, max_v };
	}
	for (int i = DEPTH; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			min_v = min(min_v, min_val[a][i]);
			min_v = min(min_v, min_val[b][i]);
			max_v = max(max_v, max_val[a][i]);
			max_v = max(max_v, max_val[b][i]);
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return { min(min_v, min(min_val[a][0], min_val[b][0])), max(max_v, max(max_val[a][0], max_val[b][0])) };
}

void dp() {
	for (int i = 1; i <= DEPTH; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			//parent[j][i]�� 0�� �ƴ� �� = �ش���ġ���� ��ΰ� ���� �� �ּ�, �ִ� �� ������Ʈ
			// j�� 2^i��° �θ������ �ִ밪 = j�� 2^i-1��° �θ������ �ִ밪 vs (j�� 2^i-1��° �θ�)�� 2^i-1��° �θ��� �ִ밪
			// �ּҵ� ��������
			if (parent[j][i]) {
				max_val[j][i] = max(max_val[j][i - 1], max_val[parent[j][i - 1]][i - 1]);
				min_val[j][i] = min(min_val[j][i - 1], min_val[parent[j][i - 1]][i - 1]);
			}
		}
	}
}

void dfs(int cur, int d) {
	visit[cur] = true;
	depth[cur] = d;
	for (int i = 0; i < graph[cur].size(); i++) {
		int child = graph[cur][i].first;
		if (!visit[child]) {
			//�ٷ� ���� �θ� ��(= 2^0��° �θ�) �� �θ� �������� �Ÿ��� �ʱ�ȭ
			parent[child][0] = cur;
			max_val[child][0] = min_val[child][0] = graph[cur][i].second;
			dfs(child, d + 1);
		}
	}
}


int main() {

	scanf("%d", &N);
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dfs(1, 0);
	dp();

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		auto ans = lca(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}