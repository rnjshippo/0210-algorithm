#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, M;
	vector<int> list;
	scanf("%d", &N);
	int a;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		list.push_back(a);
	}
	sort(list.begin(), list.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		printf("%d\n", binary_search(list.begin(), list.end(), a) ? 1 : 0);
	}
	return 0;
}