#include <iostream>
#include <vector>
using namespace std;
#define MAX 202

int parent[MAX];
int N, M;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	parent[rootA] = rootB;
}

bool isValid(vector<int>& path) {
	for (int i = 0; i < path.size() - 1; i++) {
		if(find(path[i]) != find(path[i + 1])) return false;
	}
	return true;
}

int main() {

	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
	}

	cin >> N;
	cin >> M;

	int exist;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> exist;
			if (exist) merge(i, j);
		}
	}

	vector<int> path;
	int temp;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		path.push_back(temp);
	}

	cout << (isValid(path) ? "YES" : "NO");

	return 0;
}