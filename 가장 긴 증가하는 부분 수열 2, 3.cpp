#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000005
int list[MAX];
vector<int> v;


int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
		if (i == 0) {
			v.push_back(list[i]);
			continue;
		}
		if (list[i] > v.back()) {
			v.push_back(list[i]);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), list[i]) - v.begin();
			v[idx] = list[i];
		}

	}

	int len = v.size();
	printf("%d\n", len);

	return 0;
}