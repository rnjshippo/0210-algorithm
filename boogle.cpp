#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#define MAX 26
#define INF 987654321
using namespace std;

bool visit[4][4];
bool used[4][4];
int dy[8] = { 0, 1, -1, 0, 1, -1, 1, -1 };
int dx[8] = { 1, 0, 0, -1, 1, 1, -1, -1 };
string max_word;
map<string, int> s;
vector<pair<int, int> > path;

int point_sum;

int get_index(char str) {
	return str - 'A';
}

struct Trie {
	bool finish;
	Trie* trie[MAX];
	Trie() : finish(false) {
		for (int i = 0; i < MAX; i++) trie[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++) {
			if (trie[i]) delete trie[i];
		}
	}

	void insert(const char * str) {
		if (*str == 0) {
			finish = true;
			return;
		}
		int idx = get_index(*str);
		if (trie[idx] == 0) trie[idx] = new Trie();
		trie[idx]->insert(str + 1);
	}

	bool isExist(const char* str) {
		if (*str == 0) {
			if (finish) return true;
			else return false;
		}
		
		int idx = get_index(*str);
		if (trie[idx] == 0) return false;
		return trie[idx]->isExist(str + 1);
	}
	bool isStartWith(const char* str) {
		if (*str == 0) {
			return true;
		}

		int idx = get_index(*str);
		if (trie[idx] == 0) return false;
		return trie[idx]->isStartWith(str + 1);
	}
};

int getPoint(string& a) {
	switch (a.size()) {
	case 3:
	case 4: return 1;
	case 5: return 2;
	case 6: return 3;
	case 7: return 5;
	case 8: return 11;
	default: return 0;
	}
}

void dfs(Trie* root, int y, int x, string word, string map[4], vector<pair<int, int> > path) {
	visit[y][x] = true;
	//cout << "cur :: " << word << "\n";
	path.push_back({ y, x });
	if (root->isExist(word.c_str())) {
		if (s.find(word) == s.end()) {
			s[word] = getPoint(word);
			point_sum += getPoint(word);
			//cout << "**************** add :: " << word << " point :: " << getPoint(word) << "\n";
		}
	}
	string next_word = "";
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		if (visit[ny][nx]) continue;
		next_word = word + map[ny][nx];
		//cout << "next :: " << next_word << "\n";
		if (root->isStartWith(next_word.c_str())) {
			visit[ny][nx] = true;
			//cout << "go :: " << next_word << "\n";
			dfs(root, ny, nx, next_word, map, path);
			visit[ny][nx] = false;
		}
	}
}

int main() {

	//freopen("input/A/large_hand.in", "r", stdin);
	int w, b;
	cin >> w;
	string word;
	Trie* root = new Trie();
	for (int i = 0; i < w; i++) {
		cin >> word;
		root->insert(word.c_str());
	}
	cin >> b;
	string arr[4];
	for (int i = 0; i < b; i++) {
		s.clear();
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];
		}
		string word = "";
		max_word = "";
		path.clear();
		point_sum = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				memset(visit, 0, sizeof(visit));
				word = arr[i][j];
				dfs(root, i, j, word, arr, path);
			}
		}
		for (auto e : s) {
			if (max_word == "") max_word = e.first;
			else {
				if (max_word.size() < e.first.size()) {
					max_word = e.first;
				}
			}
		}

		cout << point_sum << " " << max_word << " " << s.size() << "\n";
	}

	return 0;
}