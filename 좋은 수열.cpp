#include <iostream>
#include <string>
using namespace std;
#define MAX 82

int N;
string word = "";
string item = "123";

bool is_valid() {

	int idx = word.size() - 1;

	for (int offset = 1; offset <= word.size() / 2; offset++) {
		string sub_1 = word.substr(idx, offset);
		string sub_2 = word.substr(idx - offset, offset);
		if (sub_1.compare(sub_2) == 0) return false;
		idx -= 1;
	}

	return true;
}

void make(int toPick) {
	if (toPick == 0) {
		if (is_valid()) {
			cout << word << "\n";
			exit(0);
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (word != "" && word.back() == item[i]) continue;
		word.push_back(item[i]);
		if (is_valid()) {
			make(toPick - 1);
		}
		word.pop_back();
	}
}

int main() {

	cin >> N;
	make(N);

	return 0;
}
