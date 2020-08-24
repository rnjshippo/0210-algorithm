#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> picked;
int L, C;
bool used[20];
char input[20];
// 모음 1개 , 자음 2개 필수
void dfs(int idx, int toPick) {
	if (toPick == 0) {
		int mo = 0; //cnt1는 모음 개수
		int ja = 0; //cnt2는 자음 개수
		string ret = "";
		for (int i = 0; i < picked.size(); i++) {
			int target = input[picked[i]];
			ret += target;
			if (target == 'a' || target == 'e' || target == 'i' || target == 'o' || target == 'u') mo++;
			else ja++;
		}
		if (mo >= 1 && ja >= 2) {
			cout << ret << '\n';
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (!used[i]) {
			used[i] = true;
			picked.push_back(i);
			dfs(i, toPick - 1);
			used[i] = false;
			picked.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}

	sort(input, input + C);
	dfs(0, L);

	return 0;
}