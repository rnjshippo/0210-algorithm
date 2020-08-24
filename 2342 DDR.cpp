#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define center 0
#define top 1
#define left 2
#define bottom 3
#define right 4
#define MAXN 100001
//같은 지점 누를시 cost1
//중앙에서 상하좌우로 이동시 cost 2
//상하좌우에서 인접영역으로 이동시 cost 3
//반대편으로 이동시 cost 4


//dp[i][j][cur] = dp[i-1][j][prev] + (prev -> cur 이동비용)
//이전에 오른발 현재 오른발
//이전 왼발 현재 오른발
//오오 오왼 왼왼 왼오 -> 총 4가지
// dp[i][L][R] -> i 시간에 왼쪽발은 L을 밟고, 오른발은 R을 밟을 때 최소 누적 비용


int cur;
int pre;
int dp[MAXN][5][5];
int i = 1;

int getCost(int p1, int p2){
	if (p1 == 0)
		return 2;
	if (abs(p1 - p2) == 2)
		return 4;
	return 3;
}

//int getCost(int from, int to) {
//	int ret = 0;
//	switch (from) {
//		case center:
//			ret = 2;
//			break;
//		case top:
//			if (to == bottom) ret = 4;
//			else if (to == right || to == left) ret = 3;
//			else if (to == top) ret = 1;
//			else ret = 2;
//			break;
//		case left:
//			if (to == right) ret = 4;
//			else if (to == top || to == bottom) ret = 3;
//			else if (to == left) ret = 1;
//			else ret = 2;
//			break;
//		case bottom:
//			if (to == top) ret = 4;
//			else if (to == left || to == right) ret = 3;
//			else if (to == bottom) ret = 1;
//			else ret = 2;
//			break;
//		case right:
//			if (to == left) ret = 4;
//			else if (to == top || to == bottom) ret = 3;
//			else if (to == right) ret = 1;
//			else ret = 2;
//			break;
//	}
//	printf("%d->%d : %d\n", from, to, ret);
//	return ret;
//}

int main() {

	//for (int k = 0; k < MAXN; k++) {
		for (int j = 0; j <= 4; j++) {
			for (int a = 0; a <= 4; a++) {
				//dp[1][j][a] = 9999999;
			}
		}
	//}

	while (true) {

		scanf("%d", &cur);

		if (cur == 0) break;

		//int cost = getCost(pre, cur);
		if (i == 1) {
			printf("?\n");
			dp[i][0][cur] = 2;
			dp[i][cur][0] = 2;
			//for (int j = 1; j <= 4; j++) {
			//	dp[i][j][cur] = 987654321;
			//}
			//for (int j = 1; j <= 4; j++) {
			//	dp[i][cur][j] = 987654321;
			//}
			pre = cur;
			i++;
			for (int k = 0; k < i; k++) {
				for (int j = 0; j <= 4; j++) {
					for (int a = 0; a <= 4; a++) {
						printf("%d ", dp[k][j][a]);
					}
					printf("\n");
				}
				printf("\n");
			}
			//printf("\n");
			continue;
		}

		//오오 pre, cur
		for (int j = 0; j <= 4; j++) {
			dp[i][j][cur] = dp[i - 1][j][pre] + getCost(pre, cur);
			printf("%d %d %d -> %d %d %d , ", i-1, j, pre, i, j, cur);
		}
		printf("\n");
		//오른발->예전꺼 왼발->지금꺼
		for (int j = 0; j <= 4; j++) {
			dp[i][cur][pre] = dp[i - 1][j][pre] + getCost(j, cur);
			printf("%d %d %d -> %d %d %d , ", i-1, j, pre, i, cur, pre);
		}
		printf("\n");
		//왼왼
		for (int j = 0; j <= 4; j++) {
			dp[i][cur][j] = dp[i - 1][pre][j] + getCost(pre, cur);
			printf("%d %d %d -> %d %d %d , ", i-1, pre, j, i, cur, j);
		}
		printf("\n");
		//왼발 예전꺼, 오른발 지금꺼
		for (int j = 0; j <= 4; j++) {
			dp[i][pre][cur] = dp[i - 1][pre][j] + getCost(j, cur);
			printf("%d %d %d-> %d %d %d  , ", i-1, pre, j, i,pre, cur);
		}
		printf("\n");
		pre = cur;
		i++;

		for (int k = 0; k < i; k++) {
			for (int j = 0; j <= 4; j++) {
				for (int a = 0; a <= 4; a++) {
					printf("%d ", dp[k][j][a]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}

	return 0;
}