#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_SIZE 100
using namespace std;

int N;
char input[10][10];
int val[MAX_SIZE]; //각 알파벳의 가중치
int len;
int i, j;
int ret;

int main() {

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", input[i]);
	}
	for (i = 0; i < N; i++) {
		len = strlen(input[i]);
		for (j = 0; j < len; j++) {
			val[input[i][j] - 'A'] += (int)pow(10, len - 1 - j) * 1;
		}
	}
	sort(val, val + MAX_SIZE);
	int v = 9;
	for (i = MAX_SIZE - 1; i >= 0; i--) {
		if (val[i] != 0) {
			val[i] = val[i] * v--;
		}
	}
	for (i = 0; i < MAX_SIZE; i++) {
		ret += val[i];
	}
	printf("%d\n", ret);
	return 0;
}