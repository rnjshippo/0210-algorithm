#include <iostream>
typedef long long ll;

ll tree[400005];

ll update(int node, int index, ll value, int nodeL, int nodeR) {
	if (index < nodeL || index > nodeR) return tree[node];
	if (nodeL == nodeR) return tree[node] = value;
	int mid = (nodeL + nodeR) / 2;
	return tree[node] = update(node * 2, index, value, nodeL, mid) + update(node * 2 + 1, index, value, mid + 1, nodeR);
}

ll sum(int left, int right, int node, int nodeL, int nodeR) {
	if (right < nodeL || left > nodeR) return 0;
	if (left <= nodeL && right >= nodeR) return tree[node];
	int mid = (nodeL + nodeR) / 2;
	return sum(left, right, node * 2, nodeL, mid) + sum(left, right, node * 2 + 1, mid + 1, nodeR);
}

int main() {
	int N, Q;

	scanf("%d %d", &N, &Q);
	int temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		update(1, i, temp, 1, N);
	}

	int from, to, target, val;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d %d", &from, &to, &target, &val);
		if (from < to) {
			printf("%lld\n", sum(from, to, 1, 1, N));
		}
		else {
			printf("%lld\n", sum(to, from, 1, 1, N));
		}
		update(1, target, val, 1, N);
	}

	return 0;
}