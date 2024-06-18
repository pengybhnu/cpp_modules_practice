
module infoview;
import stl;
const String Truck::GetName(){
  SharedLock<RWMutex> lk(param_mutex_);

  return name_;
}
void Truck::UpdateName(StringView name) {
  UniqueLock<RWMutex> lk(param_mutex_);
  name_ = name;
}
