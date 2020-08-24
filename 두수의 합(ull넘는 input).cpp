#include <iostream>
#include <cstring>
using namespace std;

int getDiff(char a[], char b[]) {
	int len_a = 0;
	int len_b = 0;
	for (int i = 0; i < strlen(a); i++) {
		len_a++;
		if (a[i] == '.') {
			break;
		}
	}
	for (int i = 0; i < strlen(b); i++) {
		len_b++;
		if (b[i] == '.') {
			break;
		}
	}
	return len_a < len_b ? len_b - len_a : len_a - len_b;
}

void printSum(char a[], char b[]) {
	char ret[32];
	int last;
	bool dot = false;
	bool aIsBig = false;
	int diff = 0;
	int sizeA = strlen(a);
	int sizeB = strlen(b);

	if (sizeA > sizeB) {
		last = sizeA;
		diff = sizeA - sizeB;
		aIsBig = true;
	}
	else if(sizeA < sizeB){
		last = sizeB;
		diff = sizeB - sizeA;
	}
	else {
		last = sizeA;
	}

	int temp = 0;
	int over = 0;
	if (diff) {
		for (int i = last - 1; i >= last - diff - 1; i--) {
			ret[i] = aIsBig ? a[i] : b[i];
		}
	}
	for (int i = last - 1 - diff; i >= 0; i--) {
		if (a[i] == '.') {
			ret[i] = '.';
			dot = true;
			continue;
		}
		temp = (a[i] - '0') + (b[i] - '0');
		if (over) {
			temp++;
			if (temp < 9) {
				ret[i] = temp + '0';
				over = 0;
			}
			else {
				ret[i] = (temp % 10) + '0';
				over = 1;
			}
		}
		else {
			if (temp < 9) {
				ret[i] = temp + '0';
				over = 0;
			}
			else {
				ret[i] = (temp % 10) + '0';
				over = 1;
			}
		}
	}
	if (over) {
		memmove(ret + 1, ret, sizeof(ret));
		ret[0] = '1';
		last++;
	}
	if (dot) {
		for (int i = last - 1; i >= 0; i--) {
			if (ret[i] == '0') {
				last--;
				if (i - 1 >= 0 && ret[i - 1] == '.') {
					last--;
				}
			}
			else {
				break;
			}
		}

		for (int i = 0; i < last; i++) {
			cout << ret[i];
		}
	}
	else {
		for (int i = 0; i < last; i++) {
			cout << ret[i];
		}
	}
}

int main() {
	char firstNum[32];
	char secondNum[32];
	cin >> firstNum;
	cin >> secondNum;
	int diff = getDiff(firstNum, secondNum);
	if (strlen(firstNum) < strlen(secondNum)) {
		memmove(firstNum + diff, firstNum, sizeof(firstNum));
		for (int i = 0; i < diff; i++) {
			firstNum[i] = '0';
		}
	}
	else if (strlen(firstNum) > strlen(secondNum)) {
		memmove(secondNum + diff, secondNum, sizeof(secondNum));
		for (int i = 0; i < diff; i++) {
			secondNum[i] = '0';
		}
	}
	printSum(firstNum, secondNum);

	return 0;
}