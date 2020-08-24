#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 202
#define INF 987654321
int N, K;
int dp[MAX][MAX]; // i~j ���� ������ ������ i�� �ٲٴ� �� �ʿ��� �ּҰ�
int light[MAX]; // ���� ����

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &light[i]);
	}

	/* base : 2���� �� => ������ ���� �� 0, �ٸ��� 1 */
	for (int i = 1; i < N; i++) {
		if(light[i] != light[i+1]) dp[i][i + 1] = 1;
	}

	/* 
		3 ~ N ���� �� => a�� ���� ����� ��
		2�� �������� N������ ��� ����
	*/
	for (int a = 2; a <= N; a++) {
		for (int i = 1; i + a <= N; i++) {
			dp[i][i + a] = INF;

			//���� ���� �ٽ� i ~ i+ k , i+k+1 ~ N ���� ���ؼ� �ּڰ��� ����
			for (int k = 0; k < a; k++) {
				int temp = dp[i][i + k] + dp[i + k + 1][i + a];

				if (light[i] != light[i + k + 1]) { //i���� ���� �ٸ��� Ƚ�� 1 �߰�
					temp += 1;
				}
				dp[i][i + a] = min(dp[i][i + a], temp); //��� ���� �� �ּҰ��� ����
			}
		}
	}
	printf("%d\n", dp[1][N]); // 1��~N�� ������ �ּ� ����Ƚ�� ���

	return 0;
}
