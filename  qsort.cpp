#include<iostream>
#include<vector>

int partision(std::vector<int> &vec, int low, int high){
    int p = vec[high];
    int i = low-1;
    for (int j = low; j < high; j++)
    {
        if (vec[j]<=p) {
            i++;
            std::swap(vec[i],vec[j]);
        }
    }
    std::swap(vec[i+1],vec[high]);
    return i+1;
}

void quick_sort(std::vector<int> &vec, int low, int high){
    if (low<high)
    {
        int pi = partision(vec,low,high);
        quick_sort(vec,low,pi-1);
        quick_sort(vec,pi+1,high);
    }
    
}

int main(){
    std::vector<int> a = {-1,2,-3,-5,2,3,-123};
    quick_sort(a,0,a.size()-1);
    for(auto x:a) std::cout<<x<< ' ';
    return 0;
}