#include <stdio.h>
#include <bits/stdc++.h>
#define ROWS  102
#define COLUMNS       102

using namespace std;
int main(int, char**) 
{
    ifstream myfile("/home/vicquecon/AoC/day_9/data.txt", std::ios_base::in);
    string input;
    vector<vector<int>> matrix;
    int x_pointer = 1;
    int y_pointer = 1;
    //Grow rows by m
    matrix.resize(ROWS);
    for(int i = 0 ; i < ROWS ; ++i)
    {
        //Grow Columns by n
        matrix[i].resize(COLUMNS,99);
    }
    
    while (myfile >> input)
    {
        for (auto number = input.begin(); number != input.end(); number++)
        {
            matrix[x_pointer][y_pointer] = *number-'0';
            y_pointer ++;
        }
        x_pointer ++;
        y_pointer = 1;
    }
    vector<pair<int,int>> pairs;

    for (auto x = 0;x < matrix.size(); x++)
    {
        for (auto y = 0;y != matrix[x].size(); y++)
        {
            cout << matrix[x][y] << ',';
        }
        cout << endl;
    }
    int counter = 0;
    for (int x_it = 1;x_it != ROWS-1;x_it++)
    {
        for (int y_it = 1;y_it != COLUMNS-1;y_it++)
        if (matrix[x_it][y_it] < matrix[x_it][y_it-1] && matrix[x_it][y_it] < matrix[x_it][y_it+1] && matrix[x_it][y_it] < matrix[x_it+1][y_it] && matrix[x_it][y_it] < matrix[x_it-1][y_it])
        {
            pairs.push_back(pair<int,int>{x_it,y_it});
            counter+= matrix[x_it][y_it] + 1;
        }
    }
    cout<< pairs.size() << endl;
    cout << counter << endl;
    // END PARSE
}
