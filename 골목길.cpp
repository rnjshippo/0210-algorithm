#include <iostream>
#include <algorithm>
#include <vector>
#define V_MAX 102
#define INF 987654321
using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};
vector<Edge> edge_list;
int V, E;
int d[V_MAX]; //해당 위치까지의 최단 거리
int parent[V_MAX]; //경로 역추적
bool path[V_MAX][V_MAX];

bool bellmanFord() {
	bool cycle = false;
	vector<int> list;
	for (int i = 0; i < V; i++) {
		for (auto e : edge_list) {
			if (d[e.from] != INF && d[e.from] + e.cost < d[e.to]) {
				d[e.to] = d[e.from] + e.cost;
				parent[e.to] = e.from;
				
				if (i == V - 1) {
					cycle = true;
					list.push_back(e.to);
				}
			}
		}
		if (cycle && i == V - 1) {
			for (auto e : list) {
				if (path[e][V]) return false;
			}
			return true;
		}
	}
	return true;
}

int main() {

	cin >> V >> E;
	int from, to, cost;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> cost;
		edge_list.push_back({ from, to, -cost });
		path[from][to] = true;
	}
	for (int i = 1; i <= V; i++) {
		if (i == 1) d[i] = 0;
		else d[i] = INF;
	}
	if (bellmanFord()) {
		if (d[V] == INF) {
			cout << -1 << "\n";
			return 0;
		}
		vector<int> ret;
		ret.push_back(V);
		for (int current = parent[V]; current; current = parent[current]) {
			ret.push_back(current);
		}

		for (int i = ret.size() - 1; i >= 0; i--) {
			cout << ret[i] << " ";
		}
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}