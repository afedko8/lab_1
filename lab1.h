#pragma once
#include<vector>
struct Point {
    long double x, y;
    Point(long double x_val, long double y_val) : x(x_val), y(y_val) {}
};

int sign(long double x);
int valid(Point &a, Point &b, Point &c, Point &m);
bool in_triangle(std::vector<Point> triangle, Point p);


void lab1_2();
void lab1_3();
void lab1_5();
void lab1_6();
void lab1_7();
void lab1_8();
void lab1_9();