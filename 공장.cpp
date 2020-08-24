#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 500001
int idx_list[1000001];
int A[MAX];
int B[MAX];

int tree[4000004];

int update(int index, int value, int node, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return tree[node];
	if (nodeL == nodeR) return tree[node] = value;
	int mid = (nodeL + nodeR) / 2;
	return tree[node] = update(index, value, node * 2, nodeL, mid) + update(index, value, node * 2 + 1, mid + 1, nodeR);
}
int query(int left, int right, int node, int nodeL, int nodeR) {
	if (right < nodeL || nodeR < left) return 0;
	if (left <= nodeL && nodeR <= right) return tree[node];
	int mid = (nodeL + nodeR) / 2;
	return query(left, right, node * 2, nodeL, mid) + query(left, right, node * 2 + 1, mid + 1, nodeR);
}

int main() {

	memset(idx_list, -1, sizeof(idx_list));
	int N;
	scanf("%d", &N);
	int temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		idx_list[temp] = i;
		A[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		B[i] = idx_list[temp];
	}

	long long ret = 0;
	for (int i = 1; i <= N; i++) {
		int temp = query(B[i], N, 1, 1, N);
		ret += temp;
		update(B[i], 1, 1, 1, N);
	}
	printf("%lld\n", ret);

	return 0;
}