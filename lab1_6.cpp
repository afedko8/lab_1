#include<iostream>
#include"lab1.h"

void lab1_6(){
    long long x0,x,xd;
    long double a,b,c;
    std::cin>>x0>>x>>xd>>a>>b>>c;
    long long A = static_cast<long>(a);
    long long B = static_cast<long>(b);
    long long C = static_cast<long>(c);
    bool decimal = ((A | B) & (A | C)) != 0;
    long double f; 

    for (long long i = x0; i <= x; i++)
    {
        bool valid = 1;
       
        if (i < 0 && b != 0) {
            f = a * i * i + b;
        } else if (x > 0 && b == 0) {
            if (i - c == 0) valid = 0;
            else f = (i - a) / (i - c);
        } else {
            if (c == 0) valid = 0;
            else f = i / c;
        }
        if (valid)
        {         
            if (decimal)
            {
                std::cout<<f+0.0;
            } else{
                std::cout<<static_cast<long>(f+0.0);
            }
        }
        std::cout<<std::endl;
    }
    
}