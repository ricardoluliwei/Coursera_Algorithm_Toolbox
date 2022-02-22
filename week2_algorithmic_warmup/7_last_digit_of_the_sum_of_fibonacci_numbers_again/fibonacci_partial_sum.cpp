#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
  long long sum = 0;

  long long current = 0;
  long long next = 1;

  for (long long i = 0; i <= to; ++i) {
    if (i >= from) {
      sum += current;
    }

    long long new_current = next;
    next = next + current;
    current = new_current;
  }

  return sum % 10;
}

int fibonacci_sum(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    std::vector<long long> periodic_sum{0, 1};
    long long k;

    for (k = 1; k < n; ++k) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current %= 10;
        sum += current;
        sum %= 10;
        if (current == 1 && previous == 0 && sum == 1){
          break;
        }
        periodic_sum.push_back(sum);
    }

    return k == n ? periodic_sum[k] : periodic_sum[n % k];
}

long long get_fibonacci_partial_sum(long long from, long long to) {
  if (from == 0){
    return fibonacci_sum(to);
  }
  return (10 + fibonacci_sum(to) - fibonacci_sum(from - 1)) % 10;
}

int main() {
  long long from, to;
  std::cin >> from >> to;
  std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
