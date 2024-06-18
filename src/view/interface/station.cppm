export module infoview:station;
import stl;
export struct Point {
  double x, y, z;
};
class CrashStation {
 public:
  explicit CrashStation(StringView name) : name_(name) {
    point_ = {0.0, 0.0, 0.2};
  }
  // String GetName() { return name_; }
  String GetName();
  String Name() { return name_; }
  Point GetPoint();
  Vector<int> GetPoints();

 private:
  String name_;
  Point point_;
};
