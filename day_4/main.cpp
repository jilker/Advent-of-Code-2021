#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
struct Bingo
{
    int carton[5][5][2];
    bool winner;
    Bingo(std::vector<std::string> values)
    {
        winner = false;
    
        auto pointer = values.begin();
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                carton[x][y][0] = std::stoi(*pointer);
                carton[x][y][1] = 0;
                pointer++;
            }
        }
    };
    void plot(int type)
    {
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                std::cout << carton[x][y][type] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    bool check_hit(int value)
    {
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (carton[x][y][0] == value)
                {
                    carton[x][y][1] = 1;
                    return true;
                }
            }
        }
        return false;
    }
    bool is_winner()
    {
        if (this->winner == true)
        {
            return false;
        }
        int row = 0;
        int columm = 0;
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (carton[x][y][1] == 1)
                {
                    row++;
                }
                if (carton[y][x][1] == 1)
                {
                    columm++;
                }
            }
            if (row == 5 || columm == 5 )
            {
                this->winner = true;
                return true;
            }
            else
            {
                row = 0;
                columm = 0;
            }
        }
        return false;
    }
    int final_score(int last_value)
    {
        int sum = 0;
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (carton[x][y][1] == 0)
                    sum += carton[x][y][0];
            }
        }
        return sum * last_value;
    }
};
std::vector<int> parse_comma(std::string values)
{
    std::stringstream s_stream(values); // create string stream from the string
    std::string substr;
    std::vector<int> result;
    while (s_stream.good())
    {
        getline(s_stream, substr, ',');
        result.push_back(std::stoi(substr));
    }
    return result;
}
int main(int, char **)
{
    std::ifstream myfile("/home/vicquecon/AoC/day_4/data.txt", std::ios_base::in);
    std::vector<Bingo> cartones;
    // Numeros cantados
    std::string values;
    myfile >> values;
    std::vector<int> inputs = parse_comma(values);
    // Registrar cartones
    std::vector<std::string> numbers;
    while (myfile >> values)
    {
        numbers.push_back(values);
        if (numbers.size() == 25)
        {
            cartones.push_back(Bingo(numbers));
            numbers.clear();
        }
    }
    // END PARSE
    for (auto carton = cartones.begin(); carton != cartones.end(); carton++)
    {
        carton->plot(0);
    }
    for (auto value = inputs.begin(); value != inputs.end(); value++)
    {
        for (auto carton = cartones.begin(); carton != cartones.end(); carton++)
        {
            if (carton->check_hit(*value))
            {
                if (carton->is_winner())
                {   
                    std::cout << "Winner! Score -> " << carton->final_score(*value) << std::endl;
                }
            }
        }
    }
    // for (auto carton = cartones.begin(); carton != cartones.end(); carton++)
    // {
    //     carton->plot(0);
    // }
    std::cout << "No winners" << std::endl;
}
