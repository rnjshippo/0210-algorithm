#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 4000

int A[MAX], B[MAX], C[MAX], D[MAX];
vector<ll> right_sum;

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			right_sum.push_back(C[i] + D[j]);
		}
	}	
	sort(right_sum.begin(), right_sum.end());
	
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ll val = A[i] + B[j];
			auto lo = lower_bound(right_sum.begin(), right_sum.end(), -val);
			auto up = upper_bound(right_sum.begin(), right_sum.end(), -val);

			cnt += (up - lo);
		}
	}

	cout << cnt;

	return 0;
}