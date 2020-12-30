#include <iostream>
using namespace std;
#define MAX 102
#include <set>
#include <unordered_map>

int order[MAX];
set<int> s;
int N, K;

int findBestItem(int from) {
	unordered_map<int, int> m;

	for (auto it = s.begin(); it != s.end(); it++) {
		m[*it] = 0;
	}

	int lastItem = -1;

	for (int i = from; i < K; i++) {
		if (s.find(order[i]) != s.end()) {
			m[order[i]] += 1;
			if (m[order[i]] == 1) {
				lastItem = order[i];
			}
		}
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == 0) {
			return it->first;
		}
	}
	return lastItem;
}

int main() {

	cin >> N >> K;

	int used = 0;
	int pick_count = 0;

	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}


	for (int i = 0; i < K; i++) {
		if (s.find(order[i]) != s.end()) {
			continue;
		}

		if (used < N) {
			used++;
			s.insert(order[i]);
			continue;
		}

		int best = findBestItem(i);
		s.erase(best);
		s.insert(order[i]);
		pick_count++;
	}

	cout << pick_count;

	return 0;
}
