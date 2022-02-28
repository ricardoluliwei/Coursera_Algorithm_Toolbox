#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool IsIntersect(const Segment& seg1,const Segment& seg2){
  if (seg1.start < seg2.start){
    return seg1.end >= seg2.start;
  }

  return seg2.end >= seg1.start;
}

Segment GetIntersect(const Segment& seg1,const Segment& seg2){
  Segment ans;
  ans.start = std::max({seg1.start, seg2.start});
  ans.end = std::min({seg1.end, seg2.end});
  return ans;
}

bool Comparator(const Segment& seg1, const Segment& seg2){
  return seg1.start < seg2.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  if (segments.empty()){
    return {};
  }
  vector<int> points;
  std::sort(segments.begin(), segments.end(), Comparator);
  Segment current = segments[0];
  for (const Segment& seg: segments){
    if (IsIntersect(current, seg)){
      current = GetIntersect(current, seg);
    } else{
      points.push_back(current.start);
      current = seg;
    }
  } 

  points.push_back(current.start);
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
