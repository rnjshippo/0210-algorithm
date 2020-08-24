//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int coin[21];
//int n;
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	char ch;
//	cin >> n;
//	for (int i = 0; i < n; i++){
//		for (int j = (1 << n - 1); j > 0; j >>= 1) {
//			cin >> ch;
//			if (ch == 'H') coin[i] |= j;
//		}
//	}
//
//	return 0;
//
//}

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int coin[50];
int n;
int ans = INT_MAX;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = (1 << n - 1); j > 0; j >>= 1) {
			cout << ((j & coin[i]) ? 1 : 0);
		}
		cout << "\n";
	}
}

void sol(int pos) {
	if (pos == n) {
		int tail = 0;
		for (int i = 1; i < (1 << n); i *= 2) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (!(coin[j] & i))
					cnt++;
			}
			//cout << "head : " <<  n - cnt << " tail : " << cnt << "\n";
			if (cnt < n - cnt) tail += cnt;
			else tail += n - cnt;
		}
		//cout << "tail : " << tail << "\n";
		ans = min(ans, tail);
		cout << "return \n";
		return;
	}
	coin[pos] = ~coin[pos];
	cout << pos << "За invert\n";
	sol(pos + 1);
	coin[pos] = ~coin[pos];
	cout << pos << "За invert\n";
	sol(pos + 1);
	cout << "return \n";
}



int main() {

	char ch;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = (1 << n - 1); j > 0; ) {
			cin >> ch;
			if (ch == 'H') coin[i] |= j;
			j /= 2;
		}
	}
	print();
	sol(0);
	cout << ans << endl;
}