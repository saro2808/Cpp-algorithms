#include <iostream>

int main() {
	int n, m, k;
	std::cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	std::cin >> m;
	int *B = new int[m];
	for (int i = 0; i < m; ++i) {
		std::cin >> B[i];
	}
	std::cin >> k;

	int res = 0;
	int previous_index = 0;
	for (int j = m - 1; j >= 0; --j) {
		for (int i = previous_index; i < n && A[i] + B[j] < k; ++i) {
			++previous_index;
		}
		if (previous_index == n) {
			break;
		}
		if (A[previous_index] + B[j] == k) {
			++res;
		}
	}

	std::cout << res << std::endl;

	delete[] B;
	delete[] A;
	return 0;
}
