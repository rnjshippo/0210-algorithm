#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

int K, N;
int list[101];
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {


	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &list[i]);
		q.push(list[i]);
	}
	ll top = 0;
	for (int i = 0; i < N; i++) {
		top = q.top();
		q.pop();
		for (int j = 0; j < K; j++) {
			q.push(top * list[j]);
			if (top % list[j] == 0) break;
		}
	}
	printf("%lld\n", top);

	return 0;
}