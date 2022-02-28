#include <iostream>
#include <vector>

int get_change(int m) {
  std::vector<int> coin_values = {10, 5, 1};
  int coin_number = 0;
  for (int value: coin_values){
    coin_number += m / value;
    m %= value;
  }

  return coin_number;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
