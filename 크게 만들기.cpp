#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 500002
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	vector<char> ret;
	string str;

	cin >> N >> K; 
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		while (K && !ret.empty() && ret.back() < str[i]) {
			ret.pop_back();
			K--;
		}
		ret.push_back(str[i]);
	}

	for (int i = 0; i < ret.size() - K; i++) {
		cout << ret[i];
	}

	return 0;
}