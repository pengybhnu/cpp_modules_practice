#include <algorithm>
#include <expected>
#include <format>
#include <print>
#include <ranges>
// #include <utility>
#include <chrono>
#include <filesystem>
#include <stacktrace>
#include <span>
import basegeo;
import stl;
void deduce() {
  auto gcd = [](this auto self, int a, int b) -> int {
    return b == 0 ? a : self(b, a % b);
  };
  // gcd(20, 30);
  std::println("{}", gcd(20, 30));

  std::println("{}", std::stacktrace::current());
}
void geta(std::span<double> list){
  for (auto p : list) {
   std::print(" {} ",p); 
  }
}
void pexpected() {
  std::expected<int, int> result = 20;
  auto r2 = result.transform([](auto &r) { return r + 1; });
  std::println("r2 {}", r2.value_or(2));

  auto r3 = r2.and_then([](auto &r) -> std::expected<double, int> {
    // return {r+0.36};
    return std::unexpected<int>(8);
  });
  std::println("r3 {}", r3.value_or(2.6));
  deduce();
}
#define Ver2
int main(int argc, char *argv[]) {
  // deduce();
  pexpected();
  auto [_, d] = basegeo::BasePoint2{1, 4};
  // auto [_,d2] = std::pair<int, int>(2,3);
  std::println("d {}", d);

  std::filesystem::path p("/home/cidi/demo/cxxm/llvm.sh");
  auto status = std::filesystem::exists(p);
  if (status) {
    std::println("file {}", p.filename().c_str());
  }
  auto info = std::filesystem::last_write_time(p);

  // std::println("{}", info);
  auto cpath = std::filesystem::current_path();
  // std::println("{}", cpath.parent_path().c_str());
  Vector<double> station{1, 2, 100, 3, 90};
  geta(station);
  std::ranges::sort(station);
  // std::ranges::for_each(
  //     result,
  //     [](auto &x) {

  //     },
  //     [](auto &x) {

  //     });
  std::println("----");

  for (auto &p : station) {
    std::print("{0} ", p);
  }

  std::array s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
  std::ranges::sort(s, [](int a, int b) { return a > b; });

  return 0;
}