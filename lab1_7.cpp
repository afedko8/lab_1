#include<iostream>
#include<vector>
#include"lab1.h"
#include<Matrix.h>

void lab1_7_1(){
    Matrix<int> a(3,2);
    Matrix<int> b(2,3);
    a.input();
    b.input();
    a.mult(b);
    a.print();
}
void lab1_7_2(){
    Matrix<int> a(3,2);
    a.input();
    a.power(3);
    a.print();
}