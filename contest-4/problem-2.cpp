// id = 44804686
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> mass;
  std::vector<int> power;
  int mass_i = 0;
  int power_i = 0;
  int quantity = 0;
  while (std::cin >> mass_i) {
    std::cin >> power_i;
    mass.push_back(mass_i);
    power.push_back(power_i);
    ++quantity;
  }

  std::sort(mass.begin(), mass.end());
  std::sort(power.begin(), power.end());

  int current_mass = 0;
  int total = 0;
  for (int i = 0; i < quantity; ++i) {
    if (power[i] >= current_mass) {
      current_mass += mass[i];
      ++total;
    }
  }

  std::cout << total << std::endl;

  return 0;
}
