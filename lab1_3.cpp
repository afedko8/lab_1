#include<iostream>
#include<ctime>
bool is_prime(unsigned int x){
    if (x%2==0 && x!=2) return 0;
    
    for (size_t i = 3; i <  static_cast<int>(std::sqrt(x))+1; i+=2)
    {
        if (x%i == 0) return 0;
        
    }
    return 1;
}

void lab1_3(){
    unsigned int N;
    std::cin>>N;
    std::clock_t start = std::clock();
    for (size_t i = 1; i <= N; i++)
    {
        if (is_prime(i)) std::cout<<i<<' ';
        if (i%10 ==0) std::cout<<std::endl; 
        
    }
    std::clock_t end = std::clock();
    std::cout<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<std::endl;
}