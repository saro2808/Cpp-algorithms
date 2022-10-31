// id = 36196214
// problem 2

#include <iostream>
#include <vector>

class Segment {
 public:
  bool Contains(int x) const;
  int left;
  int right;
};

bool Segment::Contains(int x) const {
  return left <= x && x <= right;
}

int Partition(std::vector<Segment>& arr, int low, int high) {
  int pivot = arr[high].left;
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (arr[j].left < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

template <typename T>
void QuickSort(std::vector<T>& arr, int low, int high) {
  if (low < high) {
    int pi = Partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}

int CountLength(std::vector<Segment>& segment, int n) {
  int length = 0;
  for (int i = 0; i < n;) {
    int j = i + 1;
    int r = 0;
    while (j < n && segment[i].Contains(segment[j].right)) {
      j++;
      r++;
    }
    if (j < n && segment[i].Contains(segment[j].left)) {
      j++;
    }
    if (j == i + 1) {
      length += segment[i].right - segment[i].left;
      i++;
    }
    else if (j == i + r + 1) {
      length += segment[i].right - segment[i].left;
      i += r + 1;
    }
    else {
      length += segment[j - 1].left - segment[i].left;
      i = j - 1;
    }
  }
  return length;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<Segment> segment(n);
  int left = 0;
  int right = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> left >> right;
    segment[i].left = left;
    segment[i].right = right;
  }

  QuickSort(segment, 0, n - 1);

  std::cout << CountLength(segment, n) << std::endl;

  return 0;
}
