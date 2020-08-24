#include <iostream>
#include <vector>
using namespace std;

int X, Y, G; //�ʺ�, ����, ����
int E; //�ͽű���
const int INF = 987654321;

struct point {
	int x1, y1, x2, y2, t, v;
	point(int x1, int y1, int x2, int y2, int t, int v) : x1(x1), y1(y1), x2(x2), y2(y2), t(t), v(v) {}
	point() {}
};

//vector< pair< pair< pair<int, int>, pair<int, int> >, int > > edge; //���� ��ǥ���� ���� ��ǥ�̵��ϴ� ��� ����Ʈ
point list[31][31]; //��� 
vector<point> edge;

int cost[31][31]; //�ش� ���������� �ּҺ��
int type[4][2] = {  {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool cycle = false;

//dfs�� ������ ������ ���� ��� ã�Ƽ� ��� 1�� ������ �Է�
void dfs() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cost[i][j] = INF;
			if (list[i][j].v == -1) continue;//���񿡼� �̵� �Ұ���
			else if (list[i][j].v == 0) {
				if ((i == Y - 1) && (j == X - 1)) continue; //���������� ���� ���ص���
				for (int k = 0; k < 4; k++) {
					int dy = i + type[k][0];
					int dx = j + type[k][1];
					if (dy < 0 || dy == Y || dx < 0 || dx == X || list[dy][dx].v == -1) continue;
					edge.push_back(point(j, i, dx, dy, 1, 0));
				}
			}
			else {
				edge.push_back(list[i][j]);//�ڷ���Ʈ
			}
		}
	}
}

void search() {
	//��������
	cost[0][0] = 0;
	int E = edge.size(); //������ ����
	cycle = false;
	//������ �� ��ŭ �ݺ�
	int V = X * Y ; //X*Y(��� ��ǥ) - 1(������) == �����ִ� �� ����
	for (int i = 1; i <= V; i++) {
		//�ش� ������ ����üũ
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
			//���� ��ǥ -> �� �� ���� ����
			int x, y;
			scanf("%d %d", &x, &y);
			list[y][x].v = -1;
		}

		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			//�ͽű��� ���ⱸ ��ǥ, �ð� ����
			int x1, y1, x2, y2, t;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			//edge.push_back(point(x1, x2, y1, y2, t, 1));
			list[y1][x1] = point(x1, y1, x2, y2, t, 1);//����
		}

		dfs();
		cost[0][0] = 0;

		//�븸���� ����
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