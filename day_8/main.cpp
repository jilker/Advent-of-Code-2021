#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
std::map<std::string,int> STANDAR = {{"abcefg",0},{"cf",1},{"acdeg",2},{"acdfg",3},{"bcdf",4},{"abdfg",5},
                                              {"abdefg",6},{"acf",7},{"abcdefg",8},{"abcdfg",0}};

void split(const std::string value, std::vector<std::string> &signal_patterns, std::vector<std::string> &digit_output)
{
    std::stringstream ss(value);
    std::string item;
    std::string item2;
    bool second = false;
    while (std::getline(ss, item, '|'))
    {
        std::stringstream ss2(item);
        while (std::getline(ss2, item2, ' '))
        {
            if (!second)
            {
                signal_patterns.push_back(item2);
            }
            else
            {
                if (item2 != "")
                    digit_output.push_back(item2);
            }
        }
        second = true;
    }
}
int tranlate (std::string input, std::map<char,char> decoder)
{
    std::string translated;
    for (auto letter = input.begin();letter != input.end();letter++)
    {
        translated.push_back(decoder[*letter]);
    }
    std::sort(translated.begin(),translated.end());
    return STANDAR[translated];
}
int main(int, char **)
{
    std::ifstream myfile("/home/vicquecon/AoC/day_8/data.txt", std::ios_base::in);
    std::vector<std::string> signal_patterns = {};
    std::vector<std::string> digit_output = {};
    std::vector<std::vector<std::string>> list_signal_patterns = {};
    std::vector<std::vector<std::string>> list_digit_output = {};
    std::string input;
    for (std::string line; std::getline(myfile, line);)
    {
        split(line, signal_patterns, digit_output);
        list_digit_output.push_back(digit_output);
        list_signal_patterns.push_back(signal_patterns);
        signal_patterns.clear();
        digit_output.clear();
    }
    // END PARSE
    std::map<int, int> counter;
    std::map<char,char> decoder = {{'a',' '},{'b',' '},{'c',' '},{'d',' '},{'e',' '},{'f',' '},{'g',' '}};
    for (auto digit = list_signal_patterns.begin(); digit != list_signal_patterns.end(); digit++)
    {
        for (auto value = digit->begin(); value != digit->end(); value++)
        {
            switch (value->size())
            {
            case 2:
                decoder['c'] = value->at(0);
                decoder['f'] = value->at(1);
                break;
            case 3:
                decoder['a'] = value->at(0);
                decoder['c'] = value->at(1);
                decoder['f'] = value->at(2);
                break;
            case 4:
                decoder['b'] = value->at(0);
                decoder['c'] = value->at(1);
                decoder['d'] = value->at(2);
                decoder['f'] = value->at(3);
                break;
            case 7:
                decoder['a'] = value->at(0);
                decoder['b'] = value->at(1);
                decoder['c'] = value->at(2);
                decoder['d'] = value->at(3);
                decoder['e'] = value->at(4);
                decoder['f'] = value->at(5);
                decoder['g'] = value->at(6);
                break;
            default:
                break;
            }
        }
    }
    for (auto digit = list_digit_output.begin(); digit != list_digit_output.end(); digit++)
    {
        for (auto value = digit->begin(); value != digit->end(); value++)
        {
            std::cout << tranlate(*value,decoder) << std::endl;
        }
    }
    // PRIMERA PARTE
    // for (auto digit = list_digit_output.begin(); digit != list_digit_output.end(); digit++)
    // {
    //     for (auto value = digit->begin(); value != digit->end(); value++)
    //     {
    //         counter[value->size()]++;
    //     }
    // }
    // std::cout << counter[2] + counter[3] + counter[4] + counter[7] << std::endl;
}
