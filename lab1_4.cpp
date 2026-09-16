#include<iostream>
#include "lab1.h"
#include<unordered_map>

bool is_pow(int x){
    if (x<=0) return 0;
    return ((x&(x-1)) == 0) ? 1:0;
}

void lab1_4(){
    std::vector<int> v(15);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cin>>v[i];
    }
    for (size_t i = 0; i < v.size()/5; i++)
    {
        int mini = v[i*5];
        for (size_t j = 5*i; j < 5*(i+1); j++)
        {
            if (v[i]< mini) mini = v[i];
            
        }
        std::cout<<mini << ' ';
        
    }
    std::cout<<std::endl;
    std::vector<int> copy = v;
    std::sort(copy.begin(),copy.end());
    for (size_t i = 0; i < copy.size(); i++)
    {
        std::cout<<copy[i]<< ' ';
    }
    std::cout<<std::endl;
    int cnt=0;
    std::unordered_map<int,int> map;
    for (size_t i = 0; i < v.size(); i++) map[v[i]]++;
    for (auto& v : map ){
        if(v.second>1){
            cnt++;
        }
    }
    
    std::cout<<cnt<<std::endl;
    
    size_t index=0,max_len=0;
    cnt=0;
    for (size_t i = 0; i < v.size()-1; i++)
    {
        if (!is_pow(v[i])) continue;
        
        size_t j = i;
        while (j+1<v.size() && is_pow(v[j+1]) && v[j+1] == v[j]*2) j++;
        size_t len = j-i+1;
        if (len>max_len)
        {
            max_len = len;
            index = i;
        }
    }
    std::cout<<index<<std::endl;
    
    
}