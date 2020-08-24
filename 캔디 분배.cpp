#include <iostream>
#define MAX 1000000000000000000
typedef unsigned long long ull;

ull K;
ull C;
ull quotient;

void find() {
	int i = 1;
	ull temp = K;
	while (true) {
		if ((K + 1) % C == 0) {
			printf("%llu\n", (K + 1) / C);
			return;
		}
		if ((K + 1) / C > MAX) {
			printf("di IMPOSSIBLE\n");
			return;
		}
		if (K > MAX * 10) {
			printf("max IMPOSSIBLE\n");
			return;
		}
		i++;
		K = temp * i;
		printf("ch : %llu\n", K);
	}

}

int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &K, &C);

		//printf("%llu %llu \n", K, C);
		find();
	}


	return 0;
}