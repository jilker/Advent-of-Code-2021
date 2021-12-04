#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

enum Actions {
    forward,
    down,
    up
};

Actions hashit(std::string const& inString) 
{
    if (inString == "forward") return forward;
    if (inString == "down") return down;
    if (inString == "up") return up;
}

class Submarine
{
private:
    int depth_;
    int horizontal_pos_;
public:
    Submarine();
    ~Submarine();
    void do_commands(std::string action, int value);
    void info();
};

Submarine::Submarine()
{
    depth_ = 0;
    horizontal_pos_ = 0;
}

Submarine::~Submarine()
{
}

void Submarine::do_commands(std::string action, int value)
{
    switch (hashit(action))
    {
    case forward:
        horizontal_pos_+=value;
        break;
    case down:
        depth_+=value;
        break;
    case up:
        depth_-=value;
        break;
    default:
        std::cout << "Action error" << std::endl;
        break;
    }
}
void Submarine::info()
{
    std::cout << depth_*horizontal_pos_<< std::endl;
}
int main(int, char**) {
    Submarine submarine;
    std::fstream myfile("/home/vicquecon/AoC/day_2/input.txt", std::ios_base::in);
    std::string action;
    int value;
    while (myfile >> action >> value)
    {
        submarine.do_commands(action,value);
    }
    submarine.info();
}
