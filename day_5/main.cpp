#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
struct Pointer
{
    int x;
    int y;
    Pointer()
    {
        x = 0;
        y = 0;
    }
};
Pointer split(const std::string value)
{
    std::stringstream ss(value);
    std::string item;  
    Pointer pointer;
    std::getline(ss,item,',');
    pointer.x = std::stoi(item);
    std::getline(ss,item,',');
    pointer.y = std::stoi(item);
    return pointer;
}
void plot_lines (const Pointer start,const Pointer end,int (&matrix)[1000][1000])
{
    // H
    if (start.x == end.x)
    {
        if (start.y < end.y)
        {
            for(int it = start.y; it <= end.y; it++ )
            {
                matrix[it][start.x] +=1;
            }
        }
        else
        {
            for(int it = end.y; it <= start.y; it++ )
            {
                matrix[it][start.x] +=1;
            }
        }
    }
    // V
    else if (start.y == end.y)
    {
        if (start.x < end.x)
        {
            for(int it = start.x; it <= end.x; it++ )
            {
                matrix[start.y][it] +=1;
            }
        }
        else
        {
            for(int it = end.x; it <= start.x; it++ )
            {
                matrix[start.y][it] +=1;
            }
        }
    }
    // D
    else
    {
        if (start.x < end.x)
        {
            if (start.y < end.y)
            {
                for(int it = 0; it <= end.x - start.x; it++ )
                {
                    matrix[start.y + it][start.x + it] +=1;
                }
            }
            else
            {
                for(int it = 0; it <= end.x - start.x; it++ )
                {
                    matrix[start.y - it][start.x + it] +=1;
                }
            }
        }
        else
        {
            if (start.y < end.y)
            {
                for(int it = 0; it <= start.x - end.x; it++ )
                {
                    matrix[start.y + it][start.x - it] +=1;
                }
            }
            else
            {
                for(int it = 0; it <= start.x - end.x; it++ )
                {
                    matrix[start.y - it][start.x - it] +=1;
                }
            }
        }
    } 
}
void plot(int (&matrix)[1000][1000])
{
    for (int x = 0; x < 1000; x++)
    {
        for (int y = 0; y < 1000; y++)
        {
            std::cout << matrix[x][y] << " ";
        }
        std::cout << std::endl;
    }
}
int answer(int (&matrix)[1000][1000])
{
    int value = 0;
    for (int x = 0; x < 1000; x++)
    {
        for (int y = 0; y < 1000; y++)
        {
            if (matrix[x][y] > 1)
            value ++;
        }
    }
    return value;
}
int main(int, char**) {
    std::ifstream myfile("/home/vicquecon/AoC/day_5/data.txt", std::ios_base::in);
    std::string start_s;
    std::string trash_s;
    std::string end_s;
    Pointer start;
    Pointer end;
    int matrix[1000][1000] = {};
    while (myfile >> start_s >> trash_s >> end_s)
    {
        start = split(start_s);
        end = split(end_s);
        plot_lines(start,end,matrix);
    }
    plot(matrix);
    std::cout << "Answer -> "<< answer(matrix) << std::endl;
}
