#include <iostream>
#include <vector>
using namespace std;
#define MAX 1002

vector<int> graph[MAX];
bool visit[MAX];

void dfs(int cur) {
	visit[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main() {

	int V, E;
	cin >> V >> E;

	int from, to;
	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	int cnt = 0;

	for (int i = 1; i <= V; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}