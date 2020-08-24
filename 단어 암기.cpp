#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int remember = 0x3ffffff;
int N, M;
vector<int> words;

int getRememberWordsCount() {
	int count = 0;

	for (int el : words) {
		if ((remember & el) == el) count++;
	}
	return count;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

	cin >> N >> M;

	string temp;
	int type;
	char ch;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		int num = 0;
		for (int j = 0; j < temp.size(); j++) {
			num |= (1 << (temp[j] - 'a'));
		}
		words.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		cin >> type >> ch;
		ch -= 'a';
		if (type == 1) { //지우기
			remember -= (1 << (int)ch);
		}
		else { //기억
			remember |= (1 << (int)ch);
		}
		cout << getRememberWordsCount() << '\n';
	}

	return 0;
}