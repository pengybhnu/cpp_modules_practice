#include <fmt/core.h>

#include <barrier>
#include <thread>
import infoview;
import stl;
constexpr auto use_vector() {
  Vector<int> vec{1, 2, 3, 4, 5};
  return vec.size();
}

void waitall() {
  std::barrier<> b(2);
  std::thread t1([&b]() {
    fmt::println("t1 start");

    std::this_thread::sleep_for(std::chrono::seconds(1));
    b.arrive_and_wait();
    fmt::println("t1");
  });
  std::thread t2([&b]() {
    fmt::println("t2 start");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    b.arrive_and_wait();
    fmt::println("t2");
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

int main(int argc, char* argv[]) {
  fmt::println("n {}", argc);
  fmt::println("last {}", argv[argc - 1]);
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
    fmt::println("station {}", station.GetName());
    auto p = station.GetPoint();
    fmt::println("{0},{1},{2}", p.x, p.y, p.z);
  }

  String truck_id{"t1"};

  auto ret = view.GetResult(truck_id);

  if (ret) {
    auto& station = view.GetTruckById(truck_id);
    fmt::println("truck {}", station.GetName());
    fmt::println("value {}", ret.value());

  } else {
    fmt::println("error {}", ret.error());
  }
  fmt::println("size {}", use_vector());
  waitall();
  deduce();
  return 0;
}