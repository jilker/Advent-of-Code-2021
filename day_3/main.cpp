#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
std::string get_oxigen(std::vector<std::string> numbers)
{
    std::vector<std::string> numbers_aux;
    for (int pos = 0; pos != numbers[0].size(); pos ++)
    {
        int sum = 0;
        for (int number = 0; number != numbers.size(); number ++)
        {
            if (numbers[number][pos] == '1')
            {
                sum++;
            }
            else
            {
                sum--;
            }
        }
        for (int iter = 0; iter != numbers.size(); iter ++)
        {
            if (numbers[iter][pos] == '1' && sum >= 0 || numbers[iter][pos] == '0' && sum < 0)
            {
                numbers_aux.push_back(numbers[iter]);
            }
        }
        if (numbers_aux.size() == 1)
        {
            return numbers_aux[0];
        }
        numbers = numbers_aux;
        numbers_aux.clear();
    }
}

std::string get_co2(std::vector<std::string> numbers)
{
    std::vector<std::string> numbers_aux;
    for (int pos = 0; pos != numbers[0].size(); pos ++)
    {
        int sum = 0;
        for (int number = 0; number != numbers.size(); number ++)
        {
            if (numbers[number][pos] == '1')
            {
                sum++;
            }
            else
            {
                sum--;
            }
        }
        for (int iter = 0; iter != numbers.size(); iter ++)
        {
            if (numbers[iter][pos] == '1' && sum < 0 || numbers[iter][pos] == '0' && sum >= 0)
            {
                numbers_aux.push_back(numbers[iter]);
            }
        }
        if (numbers_aux.size() == 1)
        {
            return numbers_aux[0];
        }
        numbers = numbers_aux;
        numbers_aux.clear();
    }
}
int binary2int(std::string binary)
{ 
    int value = 0;
    int base = 1;
    for(auto iter = binary.rbegin(); iter != binary.rend(); ++iter)
    {
        if (*iter == '1')
        {
            value +=base;
        }
        base = base * 2;
    }
    return value;
}
int main(int, char**) 
{
    std::fstream myfile("/home/vicquecon/AoC/day_3/data.txt", std::ios_base::in);
    std::string bynary_string;
    std::vector<std::string> numbers; 
    std::string oxygen_generator_rating;
    std::string CO2_scrubber_rating;
    while (myfile >> bynary_string)
    {
        numbers.push_back(bynary_string);
    }    
    oxygen_generator_rating = get_oxigen(numbers);
    CO2_scrubber_rating = get_co2(numbers);
    int oxigen_value = binary2int(oxygen_generator_rating);
    int co2_value = binary2int(CO2_scrubber_rating);
    std::cout << oxigen_value << std::endl;
    std::cout << co2_value << std::endl;
    std::cout << oxigen_value * co2_value << std::endl;
}