#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define JOI 0
#define IOI 1
#define MAX 2002

int cake[MAX];
bool used[MAX];
int N;
vector<int> picked;

ll dp[MAX][MAX];
// i번째 횟수 / j번째 조각 // value = JOI의 개수
// dp[i][j][0] = max(dp[i - 1][j][1]) 1<=j<=N;

ll rets;

bool canPick(int idx) {
	if (used[idx]) return false;

	int prev = (idx - 1) == 0 ? N : (idx - 1);
	int next = (idx + 1) == N + 1 ? 1 : (idx + 1);
	if (used[prev] || used[next]) return true;
	else return false;

}

//ll go(int i, int j, int turn) {
//	if (i > N) {
//		ll sum = 0;
//		cout << "picked :: ";
//		for (int i = 0; i< picked.size(); i++) {
//			if (i % 2 == 0) {
//				sum += cake[picked[i]];
//			}
//		}
//		for (auto e : picked) {
//			cout << e << " ";
//		}
//		cout << "sum :: " << sum << "\n";
//		//cout << "\n";
//		rets = max(rets, sum);
//		return 0;
//	}
//
//	ll& ref = dp[i][j];
//	//if (ref != -1) {
//		//return ref;
//	//}
//	int max_val = -1;
//	int max_idx = -1;
//	int next = (turn + 1) % 2;
//	int value;
//
//	if (i == 1) {
//		for (int a = 1; a <= N; a++) {
//			used[a] = true;
//			picked.push_back(a);
//			// turn 이 JOI 일때 value를 더함
//			value = turn == JOI ? cake[a] : 0;
//			ref = max(ref, go(i + 1, a, next) + value);
//			picked.pop_back();
//			used[a] = false;
//		}
//	}
//	else {
//		if (turn == JOI) {
//			for (int a = 1; a <= N; a++) {
//				if (canPick(a)) {
//					used[a] = true;
//					picked.push_back(a);
//					// turn 이 JOI 일때 value를 더함
//					value = cake[a];
//					ref = max(ref, go(i + 1, a, next) + value);
//					picked.pop_back();
//					used[a] = false;
//				}
//			}
//		}
//		else {
//			max_idx = max_val = -1;
//			for (int i = 1; i <= N; i++) {
//				if (canPick(i)) {
//					if (max_val < cake[i]) {
//						max_val = cake[i];
//						max_idx = i;
//					}
//				}
//			}
//			value = 0;
//			used[max_idx] = true;
//			picked.push_back(max_idx);
//			ref = go(i + 1, max_idx, next) + value;
//			picked.pop_back();
//			used[max_idx] = false;
//		}
//	}
//	return ref;
//}
//


int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cake[i]);
	}
	int turn = JOI;

	//for(int j=1; j<=N; j++)
		//go(1, j, turn);

	//cout << " Ret : " << go(1, 1, turn) << "\n";

	ll ret = -1;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n\n");
	}

	for (int i = 0; i <= N; i++) {
		ret = max(ret, dp[1][i]);
	}
	cout << ret << "\n";

	cout << rets << "\n";

	return 0;
}