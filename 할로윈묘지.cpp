#include <iostream>
#include <vector>
using namespace std;

int X, Y, G; //너비, 높이, 묘비
int E; //귀신구멍
const int INF = 987654321;

struct point {
	int x1, y1, x2, y2, t, v;
	point(int x1, int y1, int x2, int y2, int t, int v) : x1(x1), y1(y1), x2(x2), y2(y2), t(t), v(v) {}
	point() {}
};

//vector< pair< pair< pair<int, int>, pair<int, int> >, int > > edge; //앞의 좌표에서 뒤의 좌표이동하는 경로 리스트
point list[31][31]; //경로 
vector<point> edge;

int cost[31][31]; //해당 지점까지의 최소비용
int type[4][2] = {  {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool cycle = false;

//dfs로 인접한 곳으로 가는 경우 찾아서 비용 1의 값으로 입력
void dfs() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cost[i][j] = INF;
			if (list[i][j].v == -1) continue;//묘비에선 이동 불가능
			else if (list[i][j].v == 0) {
				if ((i == Y - 1) && (j == X - 1)) continue; //도착지점인 경우는 안해도됨
				for (int k = 0; k < 4; k++) {
					int dy = i + type[k][0];
					int dx = j + type[k][1];
					if (dy < 0 || dy == Y || dx < 0 || dx == X || list[dy][dx].v == -1) continue;
					edge.push_back(point(j, i, dx, dy, 1, 0));
				}
			}
			else {
				edge.push_back(list[i][j]);//텔레포트
			}
		}
	}
}

void search() {
	//벨만포드
	cost[0][0] = 0;
	int E = edge.size(); //간선의 개수
	cycle = false;
	//정점의 수 만큼 반복
	int V = X * Y ; //X*Y(모든 좌표) - 1(시작점) == 갈수있는 곳 개수
	for (int i = 1; i <= V; i++) {
		//해당 정점의 간선체크
		for (int j = 0; j < E; j++) {
			auto target = edge[j];
			int time = target.t;
			int x1 = target.x1;
			int y1 = target.y1;
			int x2 = target.x2;
			int y2 = target.y2;
			if (cost[y1][x1] == INF) continue;
			if (time + cost[y1][x1] < cost[y2][x2]) {
				cost[y2][x2] = time + cost[y1][x1];
				if (i == V) {
					cycle = true;
				}
			}
		}
	}

}

int main() {


	while (true) {
		edge.clear();
		scanf("%d %d", &X, &Y);
		if (X == 0 && Y == 0) break;

		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				list[i][j] = point(0, 0, 0, 0, 0, 0);
				//if (i == 0 && j == 0) continue;
				//cost[i][j] = INF;
			}
		}
		scanf("%d", &G);
		for (int i = 0; i < G; i++) {
			//무덤 좌표 -> 올 수 없는 구역
			int x, y;
			scanf("%d %d", &x, &y);
			list[y][x].v = -1;
		}

		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			//귀신구멍 입출구 좌표, 시간 정보
			int x1, y1, x2, y2, t;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			//edge.push_back(point(x1, x2, y1, y2, t, 1));
			list[y1][x1] = point(x1, y1, x2, y2, t, 1);//텔포
		}

		dfs();
		cost[0][0] = 0;

		//밸만포드 적용
		search();

		if (cycle) {
			printf("Never\n");
		}
		else if (cost[Y - 1][X - 1] == INF) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", cost[Y - 1][X - 1]);
		}
	}

	return 0;
}