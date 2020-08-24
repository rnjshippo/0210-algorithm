#include <iostream>
#include <deque>
using namespace std;

int N, L;
deque<pair<int, int> > deq;

int main() {

	scanf("%d %d", &N, &L);
	int temp;
	int left;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		left = (i - L + 1) <= 0 ? 1 : (i - L + 1);
		if (deq.empty()) {
			deq.push_back({ i, temp });
			printf("%d ", temp);
			continue;
		}
		while (!deq.empty() && ( deq.front().first < left || deq.front().first > i ) ) deq.pop_front();
		while (!deq.empty() && deq.back().second >= temp) deq.pop_back();
		deq.push_back({ i, temp });

		printf("%d ", deq.front().second);
	}

	return 0;
}