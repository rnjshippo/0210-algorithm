#include <iostream>
#include <algorithm>
using namespace std;

int T, W;
int dp[1001][31];
int list[1001][2]; //[t][type] type 0 -> 1번 나무, type 1 -> 2번 나무

int main() {
	scanf("%d %d", &T, &W);
	for (int t = 1; t <= T; t++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 1) list[t][0] = 1;
		else list[t][1] = 1;
	}

	int index = 0;
	for (int w = 0; w <= W; w++) {
		for (int t = index; t <= T; t++) {
			if (w == 0) dp[t][w] = dp[t - 1][w] + list[t][w % 2];
			else dp[t][w] = max(dp[t - 1][w], dp[t - 1][w - 1]) + list[t][w % 2];
		}
		index++;
	}
	//for (int t = 0; t <= T; t++) {
	//	for (int w = 0; w <= W; w++) {
	//		printf("%d ", dp[t][w]);
	//	}
	//	printf("\n");
	//}

	int max_val = 0;
	for (int w = 0; w <= W; w++) {
		if (max_val < dp[T][w]) {
			max_val = dp[T][w];
		}
	}
	printf("%d\n", max_val);


	return 0;
}