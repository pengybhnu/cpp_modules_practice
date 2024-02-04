module;

// #include <string>
#include <vector>
import base;
// first thing after the Global module fragment must be a module command
export module geometry;

export class Path {
public:
  std::vector<points::Point> points;
  Path(){}
  ~Path(){}
  int PathNum(){return points.size();}
  void AddP(double x,double y){
    points.emplace_back(x,y);
  }
  points::Point getpoint(){return points.front();}

};

