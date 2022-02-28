#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <mutex>

using std::vector;
using std::string;

bool IsGreaterOrEqual(const string& s1, const string& s2){
  std::string first = s1 + s2;
  std::string second = s2 + s1;
  // std::cout << "First: " << first << ", Second: " << second << std::endl;
  return first >= second;
}

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end());
  std::cout << "sort success" << std::endl;
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  srand(0);
  for (size_t i = 0; i < a.size(); i++) {
    a[i] = std::to_string(rand() % 10);
    std::cout << a[i] << std::endl;
  }
  std::cout << largest_number(a);
}
