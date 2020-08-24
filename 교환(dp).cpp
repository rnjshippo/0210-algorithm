#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int dp[1000001][10];
string N;
int K;

int dfs(string str, int depth) {
	if (depth == K) {
		return stoi(str);
	}

	int &ret = dp[stoi(str)][depth];
	if (ret != -1) {
		return ret;
	}

	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			swap(str[i], str[j]);
			if (str[0] == '0') {
				swap(str[i], str[j]);
				continue;
			}
			ret = max(ret, dfs(str, depth + 1));
			swap(str[i], str[j]);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	cout << dfs(N, 0) << '\n';

	return 0;
}
