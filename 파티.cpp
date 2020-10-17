#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001
#define INF 987654321;

int V, E, X;
int dist[MAX];
vector<pair<int, int> > graph[MAX];

void dijkstra(int start) {

	for (int i = 1; i < MAX; i++) {
		if (i == start) {
			dist[start] = 0;
			continue;
		}
		dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int from = top.second;

		for (int i = 0; i < graph[from].size(); i++) {
			auto target = graph[from][i];
			int to = target.first;
			int cost = target.second;
			if (dist[from] + cost < dist[to]) {
				dist[to] = dist[from] + cost;
				pq.push({ dist[to], to });
			}
		}
	}
}

int main() {


	cin >> V >> E >> X;

	int from, to, cost;
	int time[MAX];
	memset(time, 0, sizeof(time));

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}


	// 도착지점에서 다른 지점까지의 거리
	dijkstra(X);
	for (int i = 1; i <= V; i++) {
		time[i] = dist[i];
	}

	for (int i = 1; i <= V; i++) {
		dijkstra(i);
		time[i] += dist[X];
	}

	cout << *max_element(time, time + MAX);



	return 0;
}