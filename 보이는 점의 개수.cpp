#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;


int dp[MAX] = { 0, 2, };

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int cnt;
	for (int i = 2; i <= 1000; ++i) {
		cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (gcd(i, j) == 1)
				++cnt;
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