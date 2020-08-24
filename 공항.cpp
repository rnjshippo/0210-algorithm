#include <iostream>
#include <cstring>
#define MAX 100005
using namespace std;

int parent[MAX];

int find(int a) {
	if (parent[a] == -1) return a;
	else return parent[a] = find(parent[a]);
}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(parent, -1, sizeof(parent));
	int G, P, temp;
	int cnt = 0;
	cin >> G >> P;
	for (int i = 0; i < P; i++) {
		cin >> temp;
		int ret = find(temp);
		if (ret == 0) break;
		cnt++;
		parent[ret] = ret - 1;
	}
	cout << cnt << "\n";

	return 0;
}