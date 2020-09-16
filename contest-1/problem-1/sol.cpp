#include <iostream>
using namespace std;

int five_to(int i) {
	int n = 1;
	for (int j = 0; j < i; j++) {
		n *= 5;
	}
	return n;
}

int main() {
	int n;
	cin >> n;
	int nyu = 0;

	int i = 1;
	int m;
	// Legandre formula
	while (1) {
		m = n / five_to(i);
		if (m > 0) {
			nyu += m;
			i++;
			continue;
		}
		break;
	}

	cout << nyu << endl;
	//system("pause");
	return 0;
}
