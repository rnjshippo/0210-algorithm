#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t, n, i;
int arr[1001];

int dp[1001][2][30];

int func(int now, int pos, int cnt) {
	if (now == t + 1)
		return 0;

	int& ref = dp[now][pos][cnt];
	if (ref != -1)
		return ref;

	if (pos == arr[now]) {
		int a1 = 0, a2 = 0;
		if (cnt < n)
			a1 = max(func(now + 1, pos, cnt) + 1, func(now + 1, pos ^ 1, cnt + 1));
		else
			a2 = func(now + 1, pos, cnt) + 1;
		return ref = max(a1, a2);
	}
	else {
		int a1 = 0, a2 = 0;
		if (cnt < n)
			a1 = max(func(now + 1, pos, cnt), func(now + 1, pos ^ 1, cnt + 1) + 1);
		else
			a2 = func(now + 1, pos, cnt);
		return ref = max(a1, a2);
	}
}

int main() {
	scanf("%d %d", &t, &n);
	for (i = 1; i <= t; ++i) {
		scanf("%d", &arr[i]);
		arr[i]--;
	}

	memset(dp, -1, sizeof(dp));

	printf("%d", func(1, 0, 0));

	return 0;
}
