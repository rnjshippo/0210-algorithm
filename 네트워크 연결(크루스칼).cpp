#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair<int, pair<int, int>> > graph;
int parent[1001];

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	parent[rootB] = rootA;
}

int main() {

	int cost = 0;
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, val;
		scanf("%d %d %d", &a, &b, &val);
		graph.push_back({ val, {a, b} });
	}
	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++) {
		int from = graph[i].second.first;
		int to = graph[i].second.second;
		if(find(from) != find(to)){
			merge(from, to);
			cost += graph[i].first;
		}
	}
	printf("%d\n", cost);


	return 0;
}