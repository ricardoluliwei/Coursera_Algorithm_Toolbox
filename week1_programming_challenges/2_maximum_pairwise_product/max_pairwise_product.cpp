#include <algorithm>
#include <iostream>
#include <vector>

int64_t MaxPairwiseProduct(const std::vector<int>& numbers) {
  int max_num = -1;
  int second_max_num = -1;
  for (int number : numbers) {
    if (number >= max_num) {
      second_max_num = max_num;
      max_num = number;
    } else if (number > second_max_num) {
      second_max_num = number;
    }
  }
  return static_cast<int64_t>(max_num) * second_max_num;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  std::cout << MaxPairwiseProduct(numbers) << "\n";
  return 0;
}
