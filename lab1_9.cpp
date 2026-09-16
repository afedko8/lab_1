#include<iostream>
#include<vector>
#include"lab1.h"

struct Student
{
    std::string name;
    unsigned long long group_number;
    std::vector<unsigned short> points;
    Student() : points(5) {}
};

struct Group_stats
{
    unsigned long long group_number;
    size_t total_students = 0;
    size_t failing_students = 0;
};

void lab1_9(){
    size_t n;
    std::cin>>n;
    std::vector<Student> st(n);
    
    for (size_t i = 0; i < n; i++)
    {
        std::cin>>st[i].name >> st[i].group_number;
        for (size_t j = 0; j < 5; j++)
        {
            std::cin>>st[i].points[j];
        }
    }
    std::sort(st.begin(),st.end(), [] (Student &a, Student &b){
        return a.group_number<b.group_number;
    });
    
    bool valid = 0;
    for (size_t i = 0; i < st.size(); i++)
    {
        unsigned int sum=0;
        for (size_t j = 0; j < st[i].points.size(); j++) sum+=st[i].points[j];
        if (sum > 4.0 * st[i].points.size())
        {
            valid = 1;
            std::cout<< st[i].name << ' ' << st[i].group_number<< std::endl;
        }
    }
    if (!valid) std::cout<< "None of the students achieved an average grade of 4.0 or higher"<< std::endl;
    
    std::vector<Group_stats> groups;
    for (size_t i = 0; i < st.size(); i++)
    {
        bool fail=0;
        for (size_t j = 0; j < st[i].points.size(); j++)
        {
            if (st[i].points[j] == 2)
            {
                fail=1;
                break;
            }
        }
         if (groups.empty() || groups.back().group_number != st[i].group_number)
            {
                groups.push_back({st[i].group_number, 1, static_cast<size_t>(fail)});
            } else{
                groups.back().total_students++;
                if (fail) groups.back().failing_students++;
            }
            
    }
    std::sort(groups.begin(), groups.end(), [](Group_stats &a, Group_stats &b){
        return a.failing_students > b.failing_students;
    });

    for (size_t i = 0; i < groups.size(); i++)
    {
        std::cout << groups[i].group_number << ' ' << groups[i].total_students << ' ' << groups[i].failing_students << std::endl;
    }
    
}