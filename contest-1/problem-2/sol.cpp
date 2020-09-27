#include <iostream>

int main() {
	int n, m;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cin >> m;
	int *b = new int[m];
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	//
	int k;
	std::cin >> k;
	int num = 0;
	int mid, left, right;
	for (int i = 0; i < n; i++) {
		left = 0;
		right = m - 1;
		while (right - left > 1) {
			mid = (left + right) / 2;
			if (a[i] + b[mid] < k) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		if (a[i] + b[left] == k || a[i] + b[right] == k) {
			num++;
		}
	}
	std::cout << num << std::endl;
	//
	delete[] a;
	delete[] b;
	return 0;
}
