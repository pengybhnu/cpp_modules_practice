module;
#include <concepts>
export module infoview;
import :truck;
import :station;
import stl;
export class DynamicView {
 public:
  DynamicView() = delete;
  explicit DynamicView(Vector<StringView> names) {
    for (int i = 0; i < names.size(); ++i) {
      crash_stations_.emplace(names.at(i), CrashStation{names.at(i)});
    }
  }
  void ClSet(StdFunction<void()> cl) { cl_ = cl; }
  void StationDebug();
  void TruckDebug();
  const CrashStation& GetStaionById(const String& id) {
    return crash_stations_.at(id);
  }
  bool HasStation(const String& id) { return crash_stations_.contains(id); }
  bool HasTruck(const String& id) { return trucks_.contains(id); }
  Truck& GetTruckById(const String& id) { return trucks_.at(id); }
  void InitTruck();
  Expected<int, String> GetResult(const String& name);

 public:
  HashMap<String, CrashStation> crash_stations_;
  HashMap<String, Truck> trucks_;
  StdFunction<void()> cl_;
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
  { v.GetName() } -> std::same_as<const String>;
};
template <typename T>
concept IStation = requires(T v) {
  IName<T>;
  { v.GetPoint() } -> std::same_as<Point>;
};
export template <IStation T>
 String GetStationName(T& devices)   {
  return devices.Name();
}
export template <IName T>
 String GetTruckName(T& devices)   {
  return devices.Name();
}