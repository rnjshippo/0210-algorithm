#include <iostream>
using namespace std;

int arr[9][9];

bool checking(int y, int x, int n) {
	for (int i = 0; i < 9; i++) {
		if (arr[y][i] == n || arr[i][x] == n)
			return false;
	}
	int Y = (y / 3) * 3;
	int X = (x / 3) * 3;
	for (int i = Y; i < Y + 3; i++) {
		for (int j = X; j < X + 3; j++) {
			if (arr[i][j] == n)
				return false;
		}
	}
	return true;
}
void sudoku() {
	int y = -1, x = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == 0) {
				y = i, x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {
		if (checking(y, x, i)) {
			arr[y][x] = i;
			sudoku();

			arr[y][x] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	sudoku();
}