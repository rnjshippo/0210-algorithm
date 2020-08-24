#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int m[501][501];
int d[1001];

int main() {

	int N;
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		d[i] = a;
		d[i + 1] = b;
	}

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i + len - 1 <= N ; i++) {
			int j = i + len - 1;
			m[i][j] = INF;
			for (int k = i; k < j; k++) {
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]);
			}
		}
	}

	printf("%d\n", m[1][N]);
	return 0;
}