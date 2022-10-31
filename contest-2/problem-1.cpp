// id = 36038385
// problem 1

#include <iostream>
#include <vector>

struct Point {
  int x;
  int y;
};

bool Arg1GreaterThanArg2(Point p0, Point p1, Point p2) {
  int x1 = p1.x - p0.x;
  int y1 = p1.y - p0.y;
  int x2 = p2.x - p0.x;
  int y2 = p2.y - p0.y;
  return y1 * x2 > y2 * x1;
}

int GetMinIndex(std::vector<Point> p, int n) {
  int min_index = 0;
  for (int i = 2; i < n; i++) {
    if (p[i].x < p[min_index].x || (p[i].x == p[min_index].x && p[i].y < p[min_index].y)) {
      min_index = i;
    }
  }
  return min_index;
}

void InsertionSort(std::vector<Point>& p, int n) {
  for (int i = 2; i < n; i++) {
    int j = i;
    Point current = p[i];
    while (j > 1 && Arg1GreaterThanArg2(p[0], current, p[j - 1])) {
      p[j] = p[j - 1];
      j--;
    }
    p[j] = current;
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }

  int min_index = GetMinIndex(p, n);
  if (min_index != 0) {
    std::swap(p[0], p[min_index]);
  }

  InsertionSort(p, n);

  for (int i = 0; i < n; i++) {
    std::cout << p[i].x << " " << p[i].y << std::endl;
  }
  return 0;
}
