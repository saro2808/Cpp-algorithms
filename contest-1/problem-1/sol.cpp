#include <iostream>

int Pow(int number, int exponent) {
	int result = 1;
	for (int j = 0; j < exponent; j++) {
		result *= number;
	}
	return result;
}

int main() {
	int n;
	std::cin >> n;
	int num_of_zeroes = 0;

	int i = 1;
	int summand = 1;
	// Legandre formula
	while (summand > 0) {
		summand = n / Pow(5, i);
		num_of_zeroes += summand;
		i++;
	}

	std::cout << num_of_zeroes << std::endl;
	return 0;
}
