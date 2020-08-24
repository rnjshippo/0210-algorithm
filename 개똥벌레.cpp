#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> top;
vector<int> bot;
int min_val = 987654321;
int min_cnt = 1;
int main() {

	int N, H;
	int a, b;
	scanf("%d %d", &N, &H);
	for (int i = 0; i < N/2; i++) {
		scanf("%d %d", &a, &b);
		bot.push_back(a);
		top.push_back(b);
	}
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());

	for (int j = 1; j <= H; j++) {
		int temp = bot.size() - (lower_bound(bot.begin(), bot.end(), j) - bot.begin());
		temp += top.size() - (upper_bound(top.begin(), top.end(), H - j) - top.begin());

		if (min_val == temp) min_cnt++;
		else if (min_val > temp) {
			min_val = temp;
			min_cnt = 1;
		}
	}

	printf("%d %d\n", min_val, min_cnt);
	return 0;
}