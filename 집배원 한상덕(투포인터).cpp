#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define INF 987654321

int N;
char town[51][51];
int height[51][51];
pair<int, int> start;

int low = INF;
int high;


int type[8][2] = { {0, 1}, {0, -1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1} };
bool visit[51][51];

int kCnt;
int findCnt;
vector<int> h;

void dfs(int y, int x) {
	if (visit[y][x]) return;
	if (height[y][x] < low || height[y][x] > high) return;
	visit[y][x] = true;
	if (town[y][x] == 'K') {
		findCnt++;
	}
	int dy, dx;
	for (int i = 0; i < 8; i++) {
		dy = y + type[i][0];
		dx = x + type[i][1];
		if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
		if (height[dy][dx] < low || height[dy][dx] > high) continue;
		if (!visit[dy][dx]) {
			dfs(dy, dx);
		}
	}
}

int main() {

	//freopen("input/postar.in.5b", "r", stdin);

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &town[i][j]);
			if (town[i][j] == 'P') start = { i, j };
		}
	}


	/* 고도를 모두 입력받은 후 중복제거 && 정렬해서 탐색*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &height[i][j]);
			h.push_back(height[i][j]);
			if (town[i][j] == 'K') {
				kCnt++;
			}
		}
	}
	sort(h.begin(), h.end());
	int temp = h[0];
	h.erase(unique(h.begin(), h.end()), h.end());

	if (h.empty()) h.push_back(temp);
	
	low = h.front();
	high = h.back();


	/* 여기서부터 투 포인터로 탐색 */

	int diff = INF;
	int s = 0;
	int e = 0;

	low = h[s];
	high = h[s];
	//diff = high - low;

	while (true) {
		findCnt = 0;
		memset(visit, 0, sizeof(visit));
		dfs(start.first, start.second);
		if (findCnt != kCnt) {
			e++;
			if (e >= h.size()) break;
			high = h[e];
		}
		else {
			diff = min(diff, high - low);
			s++;
			low = h[s];
		}
	}
	if (h.size() == 1) diff = 0;
	printf("%d\n", diff);
	return 0;
}