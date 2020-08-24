#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10005

int d[MAX];
int v[MAX];
int N;

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
	}

	if (N == 1) {
		printf("%d\n", v[1]);
	}
	else if (N == 2) {
		printf("%d\n", v[1] + v[2]);
	}
	else {
		d[1] = v[1];
		d[2] = v[1] + v[2];
		for (int i = 3; i <= N; i++) {
			int ret = 0;
			ret = max(d[i - 3] + v[i] + v[i - 1], d[i - 2] + v[i]);
			ret = max(ret, d[i - 1]);
			d[i] = ret;
		}


		printf("%d\n", d[N]);

	}

	return 0;
}