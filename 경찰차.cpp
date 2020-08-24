#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 1005
using namespace std;

int dp[MAX][MAX]; //경찰차 1이 i번째 사건, 경찰차 2가 j번째 사건을 마지막으로 처리하였을 때 이동한 거리 합의 최소값
int N, W;
pair<int, int> list[MAX];
int path[MAX];

//거리 계산
int getDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
//dp 탐색
int go(int i, int j) {
	if (i == W || j == W) {
		return 0;
	}
	int& ref = dp[i][j];
	if (ref != -1) {
		return ref;
	}
	int next = max(i, j) + 1; //다음 사건
	int car1, car2;
	if (i == 0) car1 = go(next, j) + getDist(list[next], { 1, 1 });
	else car1 = go(next, j) + getDist(list[next], list[i]);

	if (j == 0) car2 = go(i, next) + getDist(list[next], { N, N });
	else car2 = go(i, next) + getDist(list[next], list[j]);

	return ref = min(car1, car2);
}

//경로 추적
void tracking(int i, int j) {
	if (i == W || j == W) return;
	int next = max(i, j) + 1; 
	int car1, car2;
	if (i == 0) car1 = go(next, j) + getDist(list[next], { 1, 1 });
	else car1 = go(next, j) + getDist(list[next], list[i]);

	if (j == 0) car2 = go(i, next) + getDist(list[next], { N, N });
	else car2 = go(i, next) + getDist(list[next], list[j]);

	if (car1 < car2) {
		path[next] = 1;
		tracking(next, j);
	}
	else {
		path[next] = 2;
		tracking(i, next);
	}

}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &W);
	for (int i = 1; i <= W; i++) {
		scanf("%d %d", &list[i].first, &list[i].second);
	}
	printf("%d\n", go(0, 0));
	tracking(0, 0);
	for (int i = 1; i <= W; i++) {
		printf("%d\n", path[i]);
	}
	return 0;
}