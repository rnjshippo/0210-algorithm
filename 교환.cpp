#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, len;
string input;
bool used[10];
vector<int> picked;
vector<pair<int, int>> list;
int max_val = -1;

void swap(char*a, char*b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void combination(int idx, int toPick) {
	if (toPick == 0) {
		list.push_back({ picked[0], picked[1] });
		return;
	}
	
	for (int i = idx; i < len; i++) {
		if (!used[i]) {
			used[i] = true;
			picked.push_back(i);
			combination(i, toPick - 1);
			used[i] = false;
			picked.pop_back();
		}
	}
}

void permutation(int toPick) {
	if (toPick == 0) {
		string temp = input;
		for (int i = 0; i < picked.size(); i++) {
			swap(&temp[list[picked[i]].first], &temp[list[picked[i]].second]);
		}
		max_val = max(max_val, stoi(temp));
		return;
	}

	for (int i = 0; i < list.size(); i++) {
		picked.push_back(i);
		permutation(toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	input = to_string(N);
	len = input.size();
	if (len == 1) {
		cout << -1 << '\n';
	}
	else {
		combination(0, 2);
		
		picked.clear();
		//memset(used, 0, sizeof(used));
		permutation(K);

		cout << max_val << '\n';
	}

	return 0;
}