#include<iostream>
#include"lab1.h"

void lab1_2(){
    int x,cnt=0,cnt5=0, cnt2=0,tmp1,tmp2,cntd=0;
    std::cin>>x;
    int max=x, min =x, sum = 0;
    while(x != 0){
        cnt++;
        if (x<min) min = x;
        if (x>max) max = x;
        sum+=x;
        if (x>0 && x%5==0) cnt5++;
        if (x > 0 && (x & (x-1))==0) cnt2++;
        if (cnt<3)
        {   
            if (cnt == 1)
            {
                tmp1 = x;
            } else{
                tmp2 = x;
            }
            
        } else{
            if (tmp1+tmp2<x) cntd++;
            tmp1 = tmp2;
            tmp2 = x; 
        }
        std::cin>>x;
    }
    int ans = 0;
    if (cnt != 0) ans = sum/cnt;
    
    printf("a) %d b) %d c) %d d) %d a) %d ", ans, max-min, cnt5, cnt2, cntd);
}