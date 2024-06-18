module;
#include <concepts>
#include <string>
#include <unordered_map>
export module infoview;
export import :truck;
export import :station;
import stl;
export class DynamicView {
private:
  HashMap<String, CrashStation> crash_stations_;
  // std::unordered_map<std::string, CrashStation> crash_stations_;
  HashMap<String, Truck> trucks_;
  StdFunction<void()> cl_;
  String name_;

public:
  // DynamicView() = delete;
  DynamicView &&operator=(DynamicView &&other) = delete;
  DynamicView &operator=(DynamicView &other) = delete;
  explicit DynamicView(Vector<StringView> names) {
    for (int i = 0; i < names.size(); ++i) {
      crash_stations_.emplace(names.at(i), CrashStation{names.at(i)});
    }
  }
  ~DynamicView() {}
  void ClSet(StdFunction<void()> cl) { cl_ = cl; }
  void StationDebug();
  void TruckDebug();
  const CrashStation &GetStaionById(const String &id) {
    return crash_stations_.at(id);
  }
  bool HasStation(const String &id) { return crash_stations_.contains(id); }
  bool HasTruck(const String &id) { return trucks_.contains(id); }
  Truck &GetTruckById(const String &id) { return trucks_.at(id); }
  void InitTruck();
  // Expected<int, String> GetResult(const String &name);
  String GetName() { return name_; }
  String Name() { return name_; }
};

// template <typename T>
// concept IName = requires(T v) {
//   { v.Name() } -> std::convertible_to<String>;
// } && requires(T v) {
//   { v.GetName() } -> std::convertible_to<String>;
// };

template <typename T>
concept IName = requires(T v) {
  { v.Name() } -> std::convertible_to<String>;
  // { v.GetName() } -> std::same_as<const String>;
};
template <typename T>
concept IStation = requires(T v) {
  requires IName<T>;
  { v.GetPoint() } -> std::same_as<Point>;
  v.Name();
};
export template <IStation T>
  requires(std::movable<T>)
String GetStationName(T &devices) {
  return devices.Name();
}
export template <IName T> String GetTruckName(T &devices) {
  return devices.Name();
}
template <typename T>
concept IMovable = requires(T v) { requires std::movable<T>; };
export template <IName T>
  requires(std::movable<T>)
String GetName(T &devices) {
  return devices.Name();
}

#define SIZE 1
export constexpr auto SIZEC = 1;
void check() {
  // if (__cpp_lib_constexpr_memory > 201106L) {
  // }
}