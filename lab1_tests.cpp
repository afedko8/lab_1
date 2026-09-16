#include "lab1.h"
#include "lab1_tests.h"
#include <cassert>
#include <iostream>

void lab1_1_tests() {
    const std::vector<Point> right = {
        {-5.0L, -5.0L},
        { 5.0L,  5.0L},
        { 1.0L,  7.0L}
    };

    assert(in_triangle(right, Point( 0.0L, 3.0L)) == 1);
    assert(in_triangle(right, Point( 2.0L, 5.0L)) == 1);
    assert(in_triangle(right, Point( 1.0L, 7.0L)) == 1);
    assert(in_triangle(right, Point( 5.0L, 5.0L)) == 1);
    assert(in_triangle(right, Point(-5.0L,-5.0L)) == 1);
    assert(in_triangle(right, Point( 0.0L, 0.0L)) == 1);
    assert(in_triangle(right, Point( 3.0L, 6.0L)) == 1);
    assert(in_triangle(right, Point( 6.0L, 6.0L)) == 0);
    assert(in_triangle(right, Point( 0.0L, 8.0L)) == 0);
    assert(in_triangle(right, Point( 5.0L,-5.0L)) == 0);

    const std::vector<Point> t1 = {
        {0.0L, 0.0L},
        {4.0L, 0.0L},
        {1.0L, 3.0L}
    };
    assert(in_triangle(t1, Point(1.0L, 1.0L)) == 1);
    assert(in_triangle(t1, Point(2.0L, 0.0L)) == 1);
    assert(in_triangle(t1, Point(2.0L, 2.0L)) == 1);
    assert(in_triangle(t1, Point(3.0L, 3.0L)) == 0);
    assert(in_triangle(t1, Point(0.0L, 4.0L)) == 0);

    const std::vector<Point> t2 = {
        {1.0L, 1.0L},
        {4.0L, 1.0L},
        {2.0L, 4.0L}
    };
    assert(in_triangle(t2, Point(2.0L, 2.0L)) == 1);
    assert(in_triangle(t2, Point(1.0L, 1.0L)) == 1);
    assert(in_triangle(t2, Point(3.0L, 1.0L)) == 1);
    assert(in_triangle(t2, Point(3.0L, 3.0L)) == 0);
    assert(in_triangle(t2, Point(0.0L, 1.0L)) == 0);

    const std::vector<Point> t3 = {
        {-2.0L, -1.0L},
        { 3.0L, -1.0L},
        { 0.0L,  3.0L}
    };
    assert(in_triangle(t3, Point( 0.0L, 0.0L)) == 1);
    assert(in_triangle(t3, Point(-2.0L,-1.0L)) == 1);
    assert(in_triangle(t3, Point( 0.0L, 3.0L)) == 1);
    assert(in_triangle(t3, Point( 1.0L, 1.0L)) == 1);
    assert(in_triangle(t3, Point( 4.0L, 0.0L)) == 0);

}