// id = 36253556
// Problem 3

#include <iostream>
#include <random>
#include <vector>

template <typename T>
int Partition(std::vector<T>& arr, int low, int high) {
  int rand_index = high;
  if (high > low) {
    rand_index = low + rand() % (high - low);
  }
  T pivot = arr[rand_index];
  std::swap(arr[rand_index], arr[high]);
  int i = low - 1;
  for (int j = low; j <= high - 1; ++j) {
    if (arr[j] < pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

template <typename T>
T GetKthStatistic(std::vector<T> arr, int n, int k) {
  int index = -1;
  int low = 0;
  int high = n - 1;
  while (index != k) {
    index = Partition(arr, low, high);
    if (index < k) {
      low = index + 1;
    }
    else {
      high = index - 1;
    }
  }
  return arr[k];
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::cout << GetKthStatistic(arr, n, k) << std::endl;

  return 0;
}
