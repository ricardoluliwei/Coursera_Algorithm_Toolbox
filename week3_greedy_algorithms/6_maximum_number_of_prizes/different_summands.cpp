#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  // (1 + k) * k / 2 <= n
  // k <= (-1 + sqrt(1 + 8n)) / 2
  int k = std::floor((-1 + std::sqrt(1.0 + 8 * n)) / 2);
  for (int i = 1; i <= k; ++i){
    summands.push_back(i);
  } 
  summands.back() += n - (1 + k) * k / 2;
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
