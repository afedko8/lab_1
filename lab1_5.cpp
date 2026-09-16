#include<iostream>
#include "lab1.h"

void lab1_5(){
    std::vector<int> a = {1,2,3,-1,-5};
    std::vector<int> b = {-1,-2,1,2,3};
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i]< 0)
        {
            size_t j = 0;
            while (b[j]<0) j++;
            if (j>b.size()) a[i] = 0;
            else std::swap(a[i],b[j]);
        }
        
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        if (b[i]>0) b[i]=0;
        
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout<<a[i]<<' ';
    }
    std::cout<<std::endl;
    for (size_t i = 0; i < b.size(); i++)
    {
        std::cout<<b[i]<<' ';
    }
}