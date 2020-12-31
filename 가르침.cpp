#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 51

string word[MAX];
bool alpha[27];
vector<char> alphabets;
vector<char> picked;

int N, K;
int ret;

int getReadableWords() {
	int readable = 0;
	for (int i = 0; i < N; i++) {
		bool can_read = true;
		for (int j = 4; j < word[i].size() - 4; j++) {
			char cur = word[i][j];
			if (alpha[cur - 'a']) {
				continue;
			}
			can_read = false;
			break;
		}
		if (can_read) readable++;
	}
	return readable;
}

void combination(int idx, int toPick) {
	if (toPick == 0) {
		int readable = getReadableWords();
		if (ret < readable) {
			ret = readable;
		}
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			combination(i, toPick - 1);
			alpha [i] = false;
		}
	}
}

int main() {

	cin >> N >> K;

	// a n t i c 를 모르면 못 읽는다.
	if (K < 5) {
		cout << 0;
		return 0;
	}

	// 다 알면 다 읽는다.
	if (K == 26) {
		cout << N;
		return 0;
	}

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	K -= 5;

	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	combination(0, K);

	cout << ret;

	return 0;
}
