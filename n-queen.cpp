#include <iostream>
#include <vector>
using namespace std;
#define MAX 16

int N;
int cnt;
bool vertical[MAX];
bool rightTop[MAX * 2];
bool rightBottom[MAX * 2];

void dfs(int j) {
	if (j == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!vertical[i] && !rightTop[i + j] && !rightBottom[i - j + N]) {
			vertical[i] = rightTop[i + j] = rightBottom[i - j + N] = true;
			dfs(j + 1);
			vertical[i] = rightTop[i + j] = rightBottom[i - j + N] = false;
		}
	}

}

int main() {

	cin >> N;

	dfs(0);
	cout << cnt << '\n';

	return 0;
}