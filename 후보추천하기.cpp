#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int limit, K;
map<int, pair<int, int> > m; // { 후보, {추천 수, 게시된 시간} }

void pick(int num, int order) {
	// 걸려있는 후보일 때
	if (m.find(num) != m.end()) {
		m[num] = { m[num].first + 1, m[num].second };
		return;
	}

	// full
	if (limit == m.size()) {
		auto target = m.begin();
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it == m.begin()) {
				continue;
			}
			if (it->second.first < target->second.first) {
				target = it;
			}
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.first == target->second.first && it->second.second < target->second.second) {
				target = it;
			}
		}
		m.erase(target->first);
	}

	m.insert({ num, {1, order} });
}

int main() {

	cin >> limit >> K;

	int temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		pick(temp, i);
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " ";
	}

	return 0;
}