#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
#define sLeft -1 // (
#define sRight -2 // )
#define dleft -3 // [
#define dRight -4 // ]

stack<int> s;
char arr[50];

int main() {
	scanf("%s", arr);
	int size = strlen(arr);

	for (int i = 0; i < size; i++) {
		switch (arr[i]) {
		case '(':
			arr[i] = sLeft;
			break;
		case ')':
			arr[i] = sRight;
			break;
		case '[':
			arr[i] = dleft;
			break;
		case ']':
			arr[i] = dRight;
			break;
		}
	}

	int temp = 0;
	bool find = false;
	for (int i = 0; i < size; i++) {
		
		switch (arr[i]) {
			case sLeft:
			case dleft:
				s.push(arr[i]);
				break;
			case sRight:
				temp = 0;
				find = false;
				while (!s.empty()) {
					int top = s.top();
					s.pop();
					if (top == sLeft) {
						find = true;
						break;
					}
					if (top == dleft || top == dRight || top == sRight) {
						printf("%d\n", 0);
						return 0;
					}
					temp += top;
				}
				if (!find) {
					printf("%d\n", 0);
					return 0;
				}
				if (temp == 0) s.push(2);
				else s.push(2 * temp);

				break;
			case dRight:
				temp = 0;
				find = false;
				while (!s.empty()) {
					int top = s.top();
					s.pop();
					if (top == dleft) {
						find = true;
						break;
					}
					if (top == sLeft || top == sRight || top == dRight) {
						printf("%d\n", 0);
						return 0;
					}
					temp += top;
				}
				if (!find) {
					printf("%d\n", 0);
					return 0;
				}
				if (temp == 0) s.push(3);
				else s.push(3 * temp);

				break;
		}
	}
	int ret = 0;
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		if (top == sLeft || top == sRight || top == dRight || top == dleft) {
			printf("%d\n", 0);
			return 0;
		}
		ret += top;
	}
	printf("%d\n", ret);

	return 0;
}