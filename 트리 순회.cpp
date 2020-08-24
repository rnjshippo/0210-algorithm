#include <iostream>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	char val;
};

void pre_order(Node* cur) {
	if (cur) {
		cout << cur->val;
		pre_order(cur->left);
		pre_order(cur->right);
	}
}

void in_order(Node* cur) {
	if (cur) {
		in_order(cur->left);
		cout << cur->val;
		in_order(cur->right);
	}
}

void post_order(Node* cur) {
	if (cur) {
		post_order(cur->left);
		post_order(cur->right);
		cout << cur->val;
	}
}
int getCount(Node* root) {
	if (root) {
		return getCount(root->left) + getCount(root->right) + 1;
	}
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Node node[27];

	int N;
	cin >> N;
	char cur, l, r;
	for (int i = 0; i < N; i++) {
		cin >> cur >> l >> r;
		int idx = cur - 'A';
		node[idx].val = cur;
		if (l == '.') node[idx].left = NULL;
		else node[idx].left = &node[l - 'A'];

		if (r == '.') node[idx].right = NULL;
		else node[idx].right = &node[r - 'A'];
	}

	pre_order(node);
	cout << '\n';
	in_order(node);
	cout << '\n';
	post_order(node);
	cout << '\n';

	cout << getCount(node);

	return 0;
}