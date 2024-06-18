// #include <fmt/core.h>
#include <barrier>
#include <generator>
#include <iostream>
#include <print>
// #include <format>
#include <thread>
import infoview;
import stl;
import mytest;
// struct Point{
//   double x,y;
// };
// auto use_vector() {
//   Vector<int> vec{1, 2, 3, 4, 5};
//   return vec;
// }
std::generator<int> get(int n) {
  int x = 0;
  for (; x < n; x++) {
    std::println("value {}", x);

    co_yield x;
  }
  // co_return 1;
}
void waitall() {
  std::barrier<> b(2);
  std::thread t1([&b]() {
    std::println("t1 start");

    std::this_thread::sleep_for(std::chrono::seconds(1));
    b.arrive_and_wait();
    std::println("t1");
  });
  std::thread t2([&b]() {
    std::println("t2 start");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    b.arrive_and_wait();
    std::println("t2");
  });
  t1.join();
  t2.join();
}

void deduce() {
  // auto gcd = [](this auto self, int a, int b) -> int {
  //   return b == 0 ? a : self(b, a % b);
  // };
  // gcd(20, 30);
  //  std::cout << gcd(20, 30)
  //             << std::endl;
}

int main(int argc, char *argv[]) {
  std::println("n {}", argc);
  std::println("last {}", argv[argc - 1]);
  Vector<StringView> names{"s1", "s2"};
  DynamicView view{names};
  view.InitTruck();
  view.StationDebug();
  view.TruckDebug();
  view.ClSet([&names]() { int x; });
  String station_id{"s1"};
  auto re = view.HasStation(station_id);
  if (re) {
    auto station = view.GetStaionById(station_id);
    std::println("station {}", station.GetName());
    auto p = station.GetPoint();
    std::println("{0},{1},{2}", p.x, p.y, p.z);
  }

  String truck_id{"t1"};

  auto ret = true;
  //  view.GetResult(truck_id);

  if (ret) {
    auto &station = view.GetTruckById(truck_id);
    std::println("truck {}", station.GetName());
    // std::println("value {}", ret.value());

  } else {
    // std::println("error {}", ret.error());
  }
  // std::println("size {}", use_vector());
  waitall();
  deduce();
  // GetName(view);
  // Vector<int> mi(SIZE); // error
  Vector<int> mc(SIZEC);
  Point2 p2 = GetPoint();
  Point p0;
  p0.x = 0;
  p0.y = 200;
  std::println("p2 {} {}", p2.x, p2.y);

  // auto x1 = get(34);

  // std::println("x {0}", x.get());
  // std::cout << x1;
  // auto x2 = get(34);
  for (auto &&x : get(10)) {
    std::println("x {0}", x);
  }
  auto f1 = std::move(get(5));
  for (auto b = f1.begin(); f1.end() != b; b++) {
    std::println("m {0}", *b);
  }

  return 0;
}