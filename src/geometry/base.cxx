
module;
// #include <iostream>
#include <utility>

export module base;
namespace points {
export struct BasePoint {
  double x, y;
};
export class Point {
  BasePoint p;

 public:
  Point(double x,double y):p(x,y) { }
  ~Point() = default;
  std::pair<double, double> getpoint() { return {p.x, p.y}; }
};
}  // namespace pt

 int shift(int x){
    return (x<<2);
}