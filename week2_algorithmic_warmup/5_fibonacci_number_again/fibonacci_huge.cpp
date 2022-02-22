#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

long long get_fibonacci_huge(long long n, long long m) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;

  std::vector<long long> period_number{0, 1};
  long long k;
  for (k = 1; k < n; ++k) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    current %= m;
    if (current == 1 && previous == 0){
      break;
    }
    period_number.push_back(current);
  }

  return n == k ? period_number[k] : period_number[n % k];
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::cout << get_fibonacci_huge(n, m) << '\n';
}
