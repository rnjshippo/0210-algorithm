/* 세그먼트로 하면 시간초과 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 5000000

int N, L;
int tree[MAX * 4];
vector<int> list;

int update(int index, int node, int value, int nodeL, int nodeR) {
	if (index < nodeL || nodeR < index) return tree[node];
	if (nodeL == nodeR) return tree[node] = value;
	int mid = (nodeL + nodeR) / 2;
	return tree[node] = min(update(index, node * 2, value, nodeL, mid), update(index, node * 2 + 1, value, mid + 1, nodeR));
}

int query(int left, int right, int node, int nodeL, int nodeR) {
	if (right < nodeL || nodeR < left) return INT_MAX;
	if (left <= nodeL && nodeR <= right) return tree[node];
	int mid = (nodeL + nodeR) / 2;
	return min(query(left, right, node * 2, nodeL, mid), query(left, right, node * 2 + 1, mid + 1, nodeR));
}

int main() {

	scanf("%d %d", &N, &L);
	for (int i = 1; i <= MAX * 4 - 1; i++) {
		tree[i] = INT_MAX;
	}
	int temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		update(i, 1, temp, 1, N);
		list.push_back(temp);
	}
	
	int size = list.size();

	int idx = 1;
	int left;
	for (int e : list) {
		left = (idx - L + 1) <= 0 ? 1 : (idx - L + 1);
		printf("%d ", query(left, idx, 1, 1, N));
		idx++;
	}

	return 0;
}