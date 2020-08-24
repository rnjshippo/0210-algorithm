/* 세그먼트 트리 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<string, int> > words;
int tree[400005];
long long cnt;

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
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		words.push_back({ temp, 0 });
	}
	sort(words.begin(), words.end());

	int wsize = words.size();
	for (int i = 0; i < wsize; i++) {
		reverse(words[i].first.begin(), words[i].first.end());
		words[i].second = i + 1;
	}

	sort(words.begin(), words.end());

	for (int i = 0; i < n; i++) {
		cnt += query(words[i].second, n, 1, 1, n);
		update(words[i].second, 1, 1, 1, n);
	}


	cout << cnt << "\n";
	return 0;
}