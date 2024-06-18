module;
#include <iostream>
module infoview;

void DynamicView::StationDebug() {
  for (auto &[name, info] : crash_stations_) {
    std::cout << name << " " << GetStationName(info) << std::endl;
  }
}
void DynamicView::TruckDebug() {
  for (auto &[name, info] : trucks_) {
    std::cout << name << " " << GetTruckName(info) << std::endl;
  }
}
void DynamicView::InitTruck() {
  trucks_.emplace("t1", "t1");
  trucks_.emplace("t2", "t2");
}

// Expected<int, String> DynamicView::GetResult(const String &name) {
//   auto con = trucks_.contains(name);
//   if (con) {
//     return Expected<int, String>{1};
//   } else {
//     return Unexpected<String>{"not"};
//   }
// }