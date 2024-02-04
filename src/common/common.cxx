module;
#include <string>
#include "fmt/core.h"
// #include <print>
export module math;
import :other;
export {
  auto square(const auto& x) {
    return x * x;
  }  // An abbreviated function template
  const double lambda{1.303577269034296391257};
  // Conway’s constant
  enum class Oddity { Even, Odd };
  bool isOdd(int x) {
    return x % 2 != 0;
  }  // Module-local function (not exported)
  auto getOddity(int x) { return isOdd(x) ? Oddity::Odd : Oddity::Even; }

}
export double Add3(double x, double y, double z) { return x + Add(y, z); }
export struct TruckInfo{
  std::string name;
  std::string id;
  int route_id; 
  void PrintName(){
    fmt::println("name {}",name);
    fmt::println("shift {}",shift(20));
    
  }
};
