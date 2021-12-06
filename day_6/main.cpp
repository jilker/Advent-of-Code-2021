#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
void split(const std::string value,std::map<int,unsigned long> &list)
{
    std::stringstream ss(value);
    std::string item;  
    
    while (std::getline(ss,item,','))
        list[std::stoi(item)] ++;
}

int main(int, char**) {
    std::ifstream myfile("/home/vicquecon/AoC/day_6/data.txt", std::ios_base::in);
    std::map<int,unsigned long> lanternfish_v { {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0} };
    std::string input;
    while (myfile >> input)
    {
        split(input,lanternfish_v);
    }
    // END PARSE
    unsigned long new_fish = 0;
    for (int days = 0; days != 256; days ++)
    {
        for(int iter = 0; iter < 9; ++iter)
        {
            if (iter == 0)
            {
                new_fish = lanternfish_v[iter];
            }
            else
            {
                lanternfish_v[iter - 1] = lanternfish_v [iter];
            }
        }
        lanternfish_v[6] += new_fish;
        lanternfish_v[8] = new_fish;
    }

    unsigned long sum = 0;
    for(int iter = 0; iter < 9; ++iter)
    {
            sum += lanternfish_v[iter];
    }
    std::cout << sum << std::endl;
}
