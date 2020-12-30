#include <iostream>
#include <string>
using namespace std;
#define MAX 65

int N;
string map[MAX];
string result = "";

char reculsive(int sy, int sx, int len) {
	char base = map[sy][sx];
	if (len == 1) {
		return base;
	}
	bool out = false;
	for (int i = sy; i < sy + len; i++) {
		for (int j = sx; j < sx + len; j++) {
			if (base != map[i][j]) {
				result += "(";
				result += reculsive(sy, sx, len / 2);
				result += reculsive(sy, sx + len / 2, len / 2);
				result += reculsive(sy + len / 2, sx, len / 2);
				result += reculsive(sy + len / 2, sx + len / 2, len / 2);
				result += ")";
				out = true;
				break;
			}
		}
		if (out) {
			break;
		}
	}
	if (!out) {
		return base;
	}
	return '\0';
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	result += reculsive(0, 0, N);
	for (int i = 0; i < result.size(); i++) {
		if (result[i]) {
			cout << result[i];
		}
	}

	return 0;
}