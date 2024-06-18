#include <iostream>
import mytest;
 
int main(int argc, char* argv[])
{
    Point2 p2 = GetPoint();
    // print p2 x and y with cout 
    std::cout << p2.x << "," << p2.y << std::endl;  
    return 0;
}
// g++-13 -fmodules-ts -std=c++20 -x c++ src/view/interface/test.cppm  src/view/test.cpp src/mtest.cpp -o test.out