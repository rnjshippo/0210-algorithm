#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define V_MAX 502
#define E_MAX 10002
#define INF 987654321

//int cost[V_MAX][V_MAX];
bool visit[V_MAX];
int dist[V_MAX];
int parent[V_MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
struct Edge{
	int to;
	int cost;
};
vector<vector<Edge> > graph;

void bfs(int min_len) {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		auto front = q.front(); q.pop();

	}
}

int V, E;
int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int start, end;
	int from, to, val;
	while (true) {
		cin >> V >> E;
		if (V == 0 && E == 0) break;

		graph.clear();
		graph.resize(V, vector<Edge>());
		while (!pq.empty()) pq.pop();

		memset(parent, -1, sizeof(parent));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < V; i++) {
			dist[i] = INF;
		}

		cin >> start >> end;
		dist[start] = 0;

		for (int i = 0; i < E; i++) {
			cin >> from >> to >> val;
			//cost[from][to] = val;
			graph[from].push_back({ to, val });
		}

		pq.push({ 0, start });
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			if (visit[top.second]) continue;
			visit[top.second] = true;
			for (int i = 0; i < graph[top.second].size(); i++) {
				auto target = graph[top.second][i];
				dist[target.to] = min(dist[target.to], top.first + target.cost);
				if (top.first + target.cost < dist[target.to]) {
					dist[target.to] = top.first + target.cost;
					parent[target.to] = top.second;
				}
				pq.push({ dist[target.to], target.to });
			}
		}

		cout << dist[end] << "** \n";

	}
	return 0;
}