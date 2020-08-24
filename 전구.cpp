#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 202
#define INF 987654321
int N, K;
int dp[MAX][MAX]; // i~j 까지 구간의 전구를 i로 바꾸는 데 필요한 최소값
int light[MAX]; // 전구 색상

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &light[i]);
	}

	/* base : 2개씩 비교 => 같으면 변경 수 0, 다르면 1 */
	for (int i = 1; i < N; i++) {
		if(light[i] != light[i+1]) dp[i][i + 1] = 1;
	}

	/* 
		3 ~ N 개씩 비교 => a는 묶는 경우의 수
		2개 단위부터 N개까지 묶어서 연산
	*/
	for (int a = 2; a <= N; a++) {
		for (int i = 1; i + a <= N; i++) {
			dp[i][i + a] = INF;

			//묶은 것을 다시 i ~ i+ k , i+k+1 ~ N 까지 비교해서 최솟값을 저장
			for (int k = 0; k < a; k++) {
				int temp = dp[i][i + k] + dp[i + k + 1][i + a];

				if (light[i] != light[i + k + 1]) { //i값과 색이 다르면 횟수 1 추가
					temp += 1;
				}
				dp[i][i + a] = min(dp[i][i + a], temp); //모든 묶음 중 최소값을 저장
			}
		}
	}
	printf("%d\n", dp[1][N]); // 1번~N번 구간의 최소 변경횟수 출력

	return 0;
}
