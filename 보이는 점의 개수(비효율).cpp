#include <iostream>
#include <algorithm>
#include <set>
#define MAX 1001
using namespace std;

int dp[MAX] = { 0, 2, };
set<double> s;

double getIncline(double y, double x) {
	return y / x;
}

int main() {
	int cnt;
	s.insert(0);
	s.insert(1);
	for (int i = 2; i <= 1000; ++i) {
		cnt = 0;
		for (int j = 1; j <= i; j++) {
			double val = getIncline(i, j);
			if (s.find(val) == s.end()) {
				cnt++;
				s.insert(val);
			}
		}
		dp[i] = dp[i - 1] + cnt;
	}

	int C;
	int temp;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d", &temp);
		printf("%d\n", dp[temp] * 2 - 1);
	}


	return 0;
}