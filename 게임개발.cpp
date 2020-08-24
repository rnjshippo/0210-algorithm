#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bulid[505];
int indegree[505];
int N;
int ans[505]; //해당 건물까지 걸리는 시간
int time[505]; //각 건물 짓는데 걸리는 시간
vector< vector<int> > graph;

void set() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			int target = graph[front][i];
			if (--indegree[target] == 0) {
				q.push(target);
			}
			ans[target] = max(ans[target], time[target] + ans[front]);
		}
	}

}

int main() {
	scanf("%d", &N);
	graph.resize(N + 5);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		time[i] = ans[i] = t;
		
		int num;
		while (true) {
			scanf("%d", &num);
			if (num == -1) break;
			graph[num].push_back(i);
			indegree[i]++;
		}
	}
	set();
	for (int i = 1; i <= N; i++) {
		printf("%d\n", ans[i]);
	}


	return 0;
}