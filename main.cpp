#include "lab1_tests.h"
#include "lab1.h"
#include "Matrix.h"
#include<iostream>
#include<ctime>
int main(){
    long double x,y;
    std::vector<Point> tr = {Point(0,0), Point(0,0), Point(0,0)};
    for (size_t i = 0; i < 3; i++)
    {
        std::cin>>tr[i].x >> tr[i].y;
    }
    
    while (true)
    {
        std::cin>>x>>y;
        if (x == 0 && y ==0) break;
        in_triangle(tr,Point(x,y));
    }
    
    
    return 0;
}