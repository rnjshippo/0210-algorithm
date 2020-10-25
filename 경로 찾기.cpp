#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 101

bool visit[MAX];
bool graph[MAX][MAX];
vector<int> edge[MAX];

void dfs(int cur, int root) {
	for (int i = 0; i < edge[cur].size(); i++) {
		auto& next = edge[cur][i];
		if (!visit[next]) {
			visit[next] = true;
			graph[root][next] = true;
			dfs(next, root);
		}
	}
}

int main() {

	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp) {
				edge[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}