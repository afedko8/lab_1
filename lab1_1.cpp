#include"lab1.h"
#include<iostream>
int sign(long double x){
    if (std::abs(x)<1e-12) return 0;
    return x<0 ? -1:1;
}

int valid(Point &a, Point &b, Point &c, Point &m) {
    long double deltaC, deltaM;

    if (a.x == b.x) {
        deltaC = c.x - a.x;
        deltaM = m.x - a.x;
    } else {
        long double K = (a.y - b.y) / (a.x - b.x);
        long double B = a.y - K * a.x;
        deltaC = c.y - (c.x * K + B);
        deltaM = m.y - (m.x * K + B);
    }
    if (sign(deltaC) == sign(deltaM) || sign(deltaM) == 0)
        return 1;
    return 0;
}

bool in_triangle(std::vector<Point> triangle, Point p){
    // Point p;
    // std::cin>>p.x >> p.y;
    //while (!(p.x == 0.0 && p.y == 0.0)){
        // for (size_t i = 0; i < triangle.size(); i++){
        //     std::cin>>triangle[i].x >> triangle[i].y;
        // }

        if (valid(triangle[0],triangle[1], triangle[2], p) && valid(triangle[1],triangle[2], triangle[0], p) && valid(triangle[2],triangle[0], triangle[1], p)){
             std::cout<<"YES"<<std::endl;
            return 1;
        } else{
             std::cout<<"NO"<< std::endl;
            return 0;
        }
        //std::cin>>p.x >> p.y;   
    //}
}
