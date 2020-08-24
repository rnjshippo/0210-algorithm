#include <iostream>
#include <cstring>
#include <string>
#define MAX 10
using namespace std;

int get_index(const char* str) {
	return *str - '0';
}

struct Trie{
	bool finish;
	Trie* trie[MAX];
	Trie():finish(false) {
		memset(trie, 0, sizeof(trie));
	}

	~Trie() {
		for (int i = 0; i < MAX; ++i) {
			if (trie[i]) {
				delete trie[i];
			}
		}
	}
	void insert(const char* key) {
		if (*key == NULL) {
			finish = true;
			return;
		}
		int idx = get_index(key);
		if (trie[idx] == NULL) trie[idx] = new Trie();
		trie[idx]->insert(key + 1);
	}
	Trie* find(const char* key) {
		if (*key == NULL) return this;
		
		int idx = get_index(key);
		if (trie[idx] == NULL) return NULL;
		return trie[idx]->find(key + 1);
	}

	bool is_exist(const char * key) {
		if (*key == 0 && finish) return true;
		int idx = get_index(key);
		if (trie[idx] == NULL) return false;
		return trie[idx]->is_exist(key + 1);

	}

	bool is_end(const char * key) {
		if (*key == NULL) return true;
		if (finish) return false;
		int idx = get_index(key);
		return trie[idx]->is_end(key + 1);

	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	int n;
	string words[10005];
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Trie* root = new Trie();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> words[i];
			root->insert(words[i].c_str());
		}
		bool ret = true;
		for (int i = 0; i < n; i++) {
			ret = root->is_end(words[i].c_str());
			if (!ret) break;
		}
		cout << (ret ? "YES" : "NO") << "\n";
		delete root;
	}
	

	return 0;
}