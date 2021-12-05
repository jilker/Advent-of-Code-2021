#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
int main(int, char**) 
{
    std::fstream myfile("/home/vicquecon/AoC/day_3/data.txt", std::ios_base::in);
    std::string bynary_string;
    std::map<int,int> counter;
    int gamma_rate = 0;
    int epsilon_rate = 0;
    

    while (myfile >> bynary_string)
    {
        for (int it=0;it<bynary_string.size();it++)
        {
            if (bynary_string[it] == '1')
                ++counter[it];
            else
                --counter[it];
        }
    }

    int base = 1;
    for(std::map<int,int>::reverse_iterator iter = counter.rbegin(); iter != counter.rend(); ++iter)
        {
            if (iter->second > 0)
            {
                // gamma_rate = 1;
                // epsilon_rate = 0;
                gamma_rate += base;
            }
            else
            {
                // gamma_rate = 0;
                // epsilon_rate = 1;
                epsilon_rate +=base;
            }
            base = base * 2;
        }
    std::cout << epsilon_rate << std::endl;
    std::cout << gamma_rate << std::endl;
    std::cout << epsilon_rate * gamma_rate << std::endl;
}
