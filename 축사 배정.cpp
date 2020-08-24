#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 205

int d[MAX];
bool visit[MAX];
vector<int> graph[MAX];

/* ÀÌºÐ ¸ÅÄª */
bool dfs(int u) {
	for (auto next : graph[u]) {
		if (visit[next]) continue;
		visit[next] = true;
		if (d[next] == 0 || dfs(d[next])) {
			d[next] = u;
			return true;
		}
	}
	return false;
}

int main() {

	int V, E;
	cin >> V >> E;
	int temp, to;
	for (int i = 1; i <= V; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> to;
			graph[i].push_back(to);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		memset(visit, 0, sizeof(visit));
		if(dfs(i)) cnt++;
	}

	cout << cnt << "\n";

}