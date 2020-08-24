#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000005
int list[MAX];
int p[MAX] = { -1, };
vector<int> v;


int main() {

	int N; 
	scanf("%d", &N);
	p[0] = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		if (i == 0) {
			v.push_back(list[i]);
			continue;
		}
		if (list[i] > v.back()) {
			p[i] = v.size();
			v.push_back(list[i]);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), list[i]) - v.begin();
			v[idx] = list[i];
			p[i] = idx;
		}

	}

	int len = v.size();
	printf("%d\n", len);

	int idx = len - 1;
	vector<int> ret;
	for (int i = N - 1; i >= 0; i--) {
		if (idx == p[i]) {
			ret.push_back(list[i]);
			idx--;
		}
	}
	for (int i = ret.size() - 1; i >= 0; i--) {
		printf("%d ", ret[i]);
	}
	printf("\n");

	return 0;
}