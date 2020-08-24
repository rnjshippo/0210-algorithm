#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 1005
using namespace std;

int dp[MAX][MAX]; //������ 1�� i��° ���, ������ 2�� j��° ����� ���������� ó���Ͽ��� �� �̵��� �Ÿ� ���� �ּҰ�
int N, W;
pair<int, int> list[MAX];
int path[MAX];

//�Ÿ� ���
int getDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
//dp Ž��
int go(int i, int j) {
	if (i == W || j == W) {
		return 0;
	}
	int& ref = dp[i][j];
	if (ref != -1) {
		return ref;
	}
	int next = max(i, j) + 1; //���� ���
	int car1, car2;
	if (i == 0) car1 = go(next, j) + getDist(list[next], { 1, 1 });
	else car1 = go(next, j) + getDist(list[next], list[i]);

	if (j == 0) car2 = go(i, next) + getDist(list[next], { N, N });
	else car2 = go(i, next) + getDist(list[next], list[j]);

	return ref = min(car1, car2);
}

//��� ����
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