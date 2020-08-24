#include <iostream>
#define MAX 500001
int dp[2][MAX];
int N, A, B;

int main() {

	scanf("%d %d %d", &N, &A, &B);
	dp[0][A] = 1;
	dp[0][B] = 2;
	int plus, minus;

	bool out = false;
	int day = -1;
	int p = 1; // jump
	int prev, cur;
	for (int i = 1; i <= 19; i++) {
		prev = (i + 1) % 2;
		cur = i % 2;
		for (int j = 1; j <= N; j++) {
			if (dp[prev][j] == 1) {
				dp[prev][j] = 0;
				plus = j + p;
				minus = j - p;
				if (plus >= 1 && plus <= N) {
					dp[cur][plus] = 1;
				}
				if (minus >= 1 && minus <= N) {
					dp[cur][minus] = 1;
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			if (dp[prev][j] == 2) {
				dp[prev][j] = 0;
				plus = j + p;
				minus = j - p;
				
				if (plus >= 1 && plus <= N) {
					if (dp[cur][plus] == 1) {
						dp[cur][plus] += 2;
						out = true;
						day = i;
						break;
					}
					else {
						dp[cur][plus] = 2;
					}
				}
				if (minus >= 1 && minus <= N) {
					if (dp[cur][minus] == 1) {
						dp[cur][minus] += 2;
						out = true;
						day = i;
						break;
					}
					else {
						dp[cur][minus] = 2;
					}
				}
				if (out) break;
			}
		}
		
		p <<= 1;
		if (out) break;
	}

	if (out) printf("%d\n", day);
	else printf("%d\n", -1);

	return 0;
}