#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current * current;
  }

  return sum % 10;
}

int fibonacci_sum_squares(long long n) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;
  long long k;
  std::vector<long long> periodic_sum{0, 1};

  for (k = 1; k < n; ++k) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    current %= 10;
    sum += current * current;
    sum %= 10;
    if (current == 1 && previous == 0 && sum == 1) {
      break;
    }
    periodic_sum.push_back(sum);
  }

  return k == n ? periodic_sum[n] : periodic_sum[n % k];
}

int main() {
  long long n = 0;
  std::cin >> n;
  std::cout << fibonacci_sum_squares(n) << std::endl;
}
