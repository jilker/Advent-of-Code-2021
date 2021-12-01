#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
int main(int argc, char *argv[])
{
    std::fstream myfile("/home/vicquecon/AoC/day_1/data.txt", std::ios_base::in);
    std::vector<int> values;
    int counter = 0;
    int value;
    while (myfile >> value)
    {
        values.push_back(value);
        if (values.size()>3)
        {
            if (values[0]+ values[1] + values[2] < values[1]+ values[2] + values[3])
                counter++;
            values.erase(values.begin());
        }
    }
    std::cout << counter << std::endl;
}