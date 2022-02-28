#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct {
  bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
    return (double)a.first / a.second > (double)b.first / b.second;
  }
} Comparator;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  std::vector<std::pair<int,int>> values_weights;
  for (int i=0; i< weights.size(); ++i){
    values_weights.push_back(std::make_pair(values[i], weights[i]));
  }
  std::sort(values_weights.begin(), values_weights.end(), Comparator);

  for (auto [v, w]: values_weights){
    if (capacity >= w){
      capacity -= w;
      value += v;
    } else {
      value += (double) v / w * capacity;
      break;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
