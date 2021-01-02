#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int N, M;
vector<int> tree;

ll get_sum(int height) {
	ll temp = 0;
	for (auto t : tree) {
		if (t - height > 0) {
			temp += (t - height);
		}
	}
	return temp;
}

int b_search(int high) {
	int low = 0;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		ll sum = get_sum(mid);
		if (sum == M) {
			return mid;
		}
		else if (sum < M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return high;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int maxHeight = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tree.push_back(temp);
		if (maxHeight < temp) {
			maxHeight = temp;
		}
	}

	cout << b_search(maxHeight);

	return 0;
}