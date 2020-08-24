#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int N;
vector<int> picked;
bool used[10];
int t;
int ret = -1;
char arr[10][10];

void calculate() {
	char c_arr[10][10];

	int len;
	int temp = 0;
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			c_arr[i][j] = arr[i][j];
			t++;
		}
	}

	for (i = 0; i < N; i++) {
		len = strlen(c_arr[i]);
		for (j = 0; j < len; j++) {
			c_arr[i][j] = picked[c_arr[i][j] - 'A'];
			t++;
		}
	}

	for (i = 0; i < N; i++) {
		len = strlen(c_arr[i]);
		for (j = 0; j < len; j++) {
			temp += (int)pow(10, len - 1 - j) * c_arr[i][j];
			t++;
		}
	}
	ret = max(ret, temp);
}

void dfs(int toPick, int start) {
	if (toPick == 0) {
		for (int i = 0; i < picked.size(); i++) {
			printf("%d ", picked[i]);
		}
		printf("\n");
		calculate();
		t++;
		return;
	}
	for (int i = start; i <= 9; i++) {
		if (!used[i]) {
			used[i] = true;
			picked.push_back(i);
			dfs(toPick - 1, start);
			picked.pop_back();
			used[i] = false;
		}
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}
	int cnt = 0;
	bool check[10] = { false, };
	int i, j, l;
	for (i = 0; i < N; i++) {
		l = strlen(arr[i]);
		for (j = 0; j < l; j++) {
			check[arr[i][j] - 'A'] = true;
		}
	}
	for (i = 0; i < 10; i++) {
		if (check[i]) cnt++;
	}
	printf("cnt : %d\n", cnt);
	dfs(10 - cnt, 10 - cnt);

	printf("%d\n", ret);
	return 0;
}