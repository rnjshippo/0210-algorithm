#include <iostream>
typedef long long ll;
using namespace std;
#define MAX 93

ll dp[MAX];

int main() {
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	cout << dp[N];

	return 0;
}