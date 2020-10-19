#include <iostream>
#include <deque>
using namespace std;

deque<int> top_q;
deque<int> bot_q;
int robot[103];
int N, K;

void debug() {
	printf("\n------------ robot -------------\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", robot[i]);
	}
	printf("\n------------ robot -------------\n\n");
	printf("------------\n");
	for (int i = 0; i < top_q.size(); i++) {
		printf("%d ", top_q[i]);
	}
	cout << "\n";
	for (int i = 0; i < bot_q.size(); i++) {
		printf("%d ", bot_q[i]);
	}
	cout << "\n";
	printf("------------\n");
}

void move_robot() {
	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			robot[i] = 0;
			continue;
		}
		robot[i + 1] = robot[i];
		robot[i] = 0;
	}
}

void rotate() {
	int top_back = top_q.back();
	top_q.pop_back();
	int bot_front = bot_q.front();
	bot_q.pop_front();

	// 아래 벨트의 첫번째 위로 올리고
	top_q.push_front(bot_front);
	
	// 윗 벨트의 마지막 내리고
	bot_q.push_back(top_back);
	move_robot();
}



void move_robot_self() {
	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			robot[i] = 0;
			continue;
		}
		if (robot[i] && top_q[i + 1] > 0 && robot[i + 1] == 0) {
			top_q[i + 1] -= 1;
			robot[i + 1] = robot[i];
			robot[i] = 0;
		}
		if (i == 0 && robot[i] == 0) {
			if (top_q[i] > 0) {
				top_q[i] -= 1;
				robot[i] = 1;
			}
		}
	}
}

bool check_belt() {
	int count = 0;
	for (int i = 0; i < top_q.size(); i++) {
		if (top_q[i] == 0) count++;
		if (bot_q[i] == 0) count++;
	}
	return count < K;
}

int simulate() {
	int time = 0;

	while (check_belt()) {
		time += 1;
		//cout << "\nbelt rotate\n";
		rotate();
		//debug();

		//cout << "\nrobot move\n";
		move_robot_self();
		//debug();
	}
	return time;
}

int main() {

	cin >> N >> K;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		top_q.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		bot_q.push_front(temp);
	}

	//debug();
	int time = simulate();

	cout << time << '\n';
	
	return 0;
}