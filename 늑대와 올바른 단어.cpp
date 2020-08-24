#include <iostream>
#include <string>
using namespace std;

string str;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	int iter = 0;
	int cnt = 0;
	bool right = true;
	int S = str.size();
	for (int i = 0; i < S; i++) {

		switch (str[i]) {
			case 'w':
				if (i == S - 1) {
					right = false;
					break;
				}
				if (i == 0) {
					iter = 1;
					continue;
				}
				if (str[i - 1] == 'w') {
					iter++;
				}
				else if (str[i - 1] == 'f') {
					iter = 1;
				}
				else {
					right = false;
					break;
				}
				break;
			case 'o':
				if (i == S - 1) {
					right = false;
					break;
				}
				if (i == 0) {
					right = false;
					break;
				}
				if (str[i - 1] == 'w') {
					cnt = 1;
					if (i + 1 < S && str[i + 1] != 'o') {
						if (str[i + 1] != 'l') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else if (str[i - 1] == 'o') {
					cnt++;
					if (i + 1 < S && str[i + 1] != 'o') {
						if (str[i + 1] != 'l') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else {
					right = false;
					break;
				}
				break;
			case 'l':
				if (i == S - 1) {
					right = false;
					break;
				}
				if (i == 0) {
					right = false;
					break;
				}
				if (str[i - 1] == 'o') {
					cnt = 1;
					if (i + 1 < S && str[i + 1] != 'l') {
						if (str[i + 1] != 'f') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else if (str[i - 1] == 'l') {
					cnt++;
					if (i + 1 < S && str[i + 1] != 'l') {
						if (str[i + 1] != 'f') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else {
					right = false;
					break;
				}
				break;
			case 'f':
				if (i == 0) {
					right = false;
					break;
				}
				if (str[i - 1] == 'l') {
					cnt = 1;
					if (i == S - 1) {
						if (cnt != iter) {
							right = false;
							break;
						}
					}
					if (i + 1 < S && str[i + 1] != 'f') {
						if (str[i + 1] != 'w') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else if (str[i - 1] == 'f') {
					cnt++;
					if (i == S - 1) {
						if (cnt != iter) {
							right = false;
							break;
						}
					}
					if (i + 1 < S && str[i + 1] != 'f') {
						if (str[i + 1] != 'w') {
							right = false;
							break;
						}
						if (cnt != iter) {
							right = false;
							break;
						}
					}
				}
				else {
					right = false;
					break;
				}

				break;
		}
	}

	cout << right << '\n';
	return 0;
}