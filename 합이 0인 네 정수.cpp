#include <iostream>
#include <algorithm>
#define MAX 4000
typedef long long ll;
using namespace std;

int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
int N;

ll back[MAX * MAX];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			back[idx++] = C[i] + D[j];
		}
	}

	sort(back, back + N * N);
	ll cnt = 0;
	ll sum;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum = A[i] + B[j];
			int up = upper_bound(back, back + N * N, -sum) - back;
			int lo = lower_bound(back, back + N * N, -sum) - back;
			if (-sum == back[lo]) {
				cnt += (up - lo);
			}
		}
	}
	printf("%lld\n", cnt);

	return 0;
}