// id = 36503358
// Problem 4

#include <iostream>

// Returns the index of num in the sorted array arr[]
int GetIndex(const int *arr, int left, int right, int num) {
  if (num > arr[right]) {
    return right + 1;
  }
  int middle = 0;
  while (right - left > 1) {
    middle = (left + right) / 2;
    if (arr[middle] > num) {
      right = middle;
    }
    else {
      left = middle;
    }
  }
  if (arr[left] >= num) {
    return left;
  }
  return right;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int *arr = new int[k];
  int num = 0;
  std::cin >> arr[0];
  for (int i = 1; i < k; ++i) {
    std::cin >> num;
    int j = GetIndex(arr, 0, i - 1, num);
    for (int l = i; l > j; --l) {
      arr[l] = arr[l - 1];
    }
    arr[j] = num;
  }

  for (int i = k; i < n; ++i) {
    std::cin >> num;
    int j = GetIndex(arr, 0, k - 1, num);
    if (j < k) {
      for (int l = k; l > j; --l) {
        arr[l] = arr[l - 1];
      }
      arr[j] = num;
    }
  }

  for (int i = 0; i < k; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  // delete[] arr;
  return 0;
}
