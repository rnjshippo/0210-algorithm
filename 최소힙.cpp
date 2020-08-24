#include <iostream>

int heap[400000];
int bottom;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void pop() {
	if (bottom == 0) {
		printf("%d\n", 0);
	}
	else {
		printf("%d\n", heap[1]);
		swap(&heap[1], &heap[bottom]);
		bottom--;

		int parent = 1;
		int child = parent * 2;
		if (child + 1 <= bottom) {
			child = heap[child] < heap[child + 1] ? child : child + 1;
		}
		while (child <= bottom && heap[child] < heap[parent]) {
			swap(&heap[parent], &heap[child]);
			parent = child;
			child = parent * 2;
			if (child + 1 <= bottom) {
				child = heap[child] < heap[child + 1] ? child : child + 1;
			}
		}
	}
}
void push(int val) {
	heap[++bottom] = val;
	int child = bottom;
	int parent = child / 2;
	while (child > 1 && heap[child] < heap[parent]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int main() {

	int N, input;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if(input == 0){
			pop();
		}
		else {
			push(input);
		}
	}


	return 0;
}