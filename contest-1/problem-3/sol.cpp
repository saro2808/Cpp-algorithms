#include <iostream>

int GetIndex(int *arr, int left, int right, int num) {
	if (num > arr[right])
		return right + 1;
	int middle = (left + right) / 2;
	while (right - left > 1) {
		middle = (left + right) / 2;
		if (arr[middle] > num)
			right = middle;
		else
			left = middle;
	}
	if (arr[left] >= num)
		return left;
	return right;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	int *A = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	int *B = new int[m];
	for (int i = 0; i < m; ++i) {
		std::cin >> B[i];
	}

	for (int i = 0; i < m; ++i) {
		if (A[n - 1] < B[i]) {
			std::cout << n << " ";
			continue;
		}
		int left = 0, right = 1;
		while (A[right] < B[i]) {
			left = right;
			right *= 2;
			if (right > n - 1) {
				right = n - 1;
			}
		}
		std::cout << GetIndex(A, left, right, B[i]) << " ";
	}

	delete[] B;
	delete[] A;
	return 0;
}
