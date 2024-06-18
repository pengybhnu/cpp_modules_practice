module mytest;
// struct Point2{
//   double x,y;
// };
struct Point3{
  double x,y;
};
Point3 GetPoint3(){
  return {3.69,89};
}
Point2 GetPoint(){
  auto p3 = GetPoint3();
  return {p3.x,p3.y};
}
