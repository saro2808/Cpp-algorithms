#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int *b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	//
	int left, right, mid;
	for (int i = 0; i < m; i++) {
		if (a[n - 1] < b[i]) {
			cout << n << " ";
			continue;
		}
		left = 0;
		right = n - 1;
		while (right - left > 1) {
			mid = (left + right) / 2;
			if (a[mid] <= b[i]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		if (a[left] >= b[i]) {
			cout << left << " ";
		}
		else {
			cout << right << " ";
		}
	}
	//
	delete[] a;
	delete[] b;
	system("pause");
	return 0;
}
