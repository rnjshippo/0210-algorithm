#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

string coin[21];
int n;
vector<int> picked;
int ans = INF;

int checkCol() {
	int back = 0;
	for (int j = 0; j < n; j++) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			if (coin[i][j] == 'T') temp++;
		}
		back += temp < n - temp ? temp : n - temp;
	}
	return back;
}

void dfs(int toPick) {
	if (toPick == 0) {
		for (int i = 0; i < n; i++) {
			if (picked[i] == 1) {
				for (int j = 0; j < n; j++) {
					coin[i][j] = coin[i][j] == 'H' ? 'T' : 'H';
				}
			}
		}
		ans = min(ans, checkCol());
		for (int i = 0; i < n; i++) {
			if (picked[i] == 1) {
				for (int j = 0; j < n; j++) {
					coin[i][j] = coin[i][j] == 'H' ? 'T' : 'H';
				}
			}
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		picked.push_back(i);
		dfs(toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dfs(n);
	cout << ans << "\n";
}