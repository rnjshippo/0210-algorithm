#include <iostream>
#define MAXN 1000005
int n, m;
int parent[MAXN];

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	parent[rootA] = rootB;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if (type == 0) {
			//ÇÕÁýÇÕ
			merge(a, b);
		}
		else {
			if (find(a) == find(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}