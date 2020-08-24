#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1005
using namespace std;

int dp[MAX][MAX];
string str1, str2;

int main() {

	cin >> str1 >> str2;
	for (int i = 1; i <= str1.length(); i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= str2.length(); j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
		}
	}
	printf("%d\n", dp[str1.length()][str2.length()]);

	return 0;
}