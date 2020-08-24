#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

struct point {
	int sx, sy, x, y, t, v;
	point(int sx, int sy, int x, int y, int t, int v) :sx(sx), sy(sy), x(x), y(y), t(t), v(v) {}
	point() {}
};

int w, h, g, E, a, b, c, d, e, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, ret[31][31];
point arr[31][31];
vector<point> edge;

int main() {
	while (1) {
		edge.clear();
		scanf("%d %d", &w, &h);
		if (w == 0 & h == 0)return 0;
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)arr[i][j] = point(0, 0, 0, 0, 0, 0);
		scanf("%d", &g);
		for (int i = 0; i < g; i++) {
			scanf("%d %d", &a, &b);
			arr[b][a].v = -1;
		}
		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			arr[b][a] = point(a, b, c, d, e, 1);//����
		}
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) {
			ret[i][j] = 1e9;
			if (arr[i][j].v == -1)continue;//���񿡼� �̵� �Ұ���
			else if (arr[i][j].v == 0) {
				if (i == h - 1 && j == w - 1)continue;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					//����� ���� �����δ� �̵� �Ұ���
					if (ny < 0 || ny == h || nx < 0 || nx == w || arr[ny][nx].v == -1)continue;
					//�ܵ�� �����¿�� ��ĭ�� �̵�
					edge.push_back(point(j, i, nx, ny, 1, 0));
				}
			}
			else edge.push_back(arr[i][j]);//�ڷ���Ʈ
		}
		ret[0][0] = 0;//������ �ʱ�ȭ
		for (int i = 0; i < w*h; i++) {
			int cnt = 0;//���ǻ���Ŭ �Ǵ�
			for (point now : edge) {
				int sx = now.sx, sy = now.sy, ex = now.x, ey = now.y, t = now.t, v = now.v;
				if (ret[sy][sx] == 1e9)continue;
				if (ret[ey][ex] > ret[sy][sx] + t) {
					ret[ey][ex] = ret[sy][sx] + t;
					cnt++;
				}
			}
			if (i == w * h - 1) {//V*E��ŭ ��������
				if (cnt)printf("Never\n");
				else if (ret[h - 1][w - 1] == 1e9)printf("Impossible\n");
				else printf("%d\n", ret[h - 1][w - 1]);
			}
		}
	}
}
