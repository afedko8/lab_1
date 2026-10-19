#include<iostream>
#include<vector>
#include"lab1.h"
#include"Matrix.h"

int lab1_7_1(){
    size_t n,m,n1,m1;
    std::cin>>n>>m>>n1>>m1;
    Matrix<int> a(n,m);
    Matrix<int> b(n1,m1);
    a.input();
    b.input();
    a.mult(b);
    a.print();
    return 0;
}
void lab1_7_2(){
    size_t n,m;
    std::cin>>n>>m;
    Matrix<int> a(3,2);
    a.input();
    a.power(3);
    a.print();
}

int main(){
    lab1_7_1();
    lab1_7_2();
}