export module infoview:truck;
import stl;
export {
  class Truck {
   private:
    String name_;
    String park_id_;
    RWMutex param_mutex_;

   public:
    explicit Truck(StringView name) : name_(name) {}
    const String GetName() ;
    String Name() { return name_; }
    void UpdateName(StringView name);
  };
}