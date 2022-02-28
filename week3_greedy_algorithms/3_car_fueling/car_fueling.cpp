#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
  int refills = 0;
  int remain_tank = tank;
  int travel_distance = 0;
  stops.push_back(dist);
  for (int s: stops){
    int gap = s - travel_distance;
    remain_tank -= gap;
    if (remain_tank < 0){
      if (gap > tank){
        return -1;
      }
      ++refills;
      remain_tank = tank - gap;
    }
    travel_distance = s;
  }
  return refills;
}

int main() {
  int d = 0;
  cin >> d;
  int m = 0;
  cin >> m;
  int n = 0;
  cin >> n;

  vector<int> stops(n);
  for (size_t i = 0; i < n; ++i) cin >> stops.at(i);

  cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}
