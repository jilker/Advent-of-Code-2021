#include <stdio.h>
#include <bits/stdc++.h>
void split(const std::string value,std::vector<int> &list)
{
    std::stringstream ss(value);
    std::string item;  
    
    while (std::getline(ss,item,','))
        list.push_back(std::stoi(item));
}
double findMedian(std::vector<int> a, int n)
{
  
    // even
    if (n % 2 == 0) {
        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());
        nth_element(a.begin(),
                    a.begin() + (n - 1) / 2,
                    a.end());
        return (double)(a[(n - 1) / 2]
                        + a[n / 2])
               / 2.0;
    }
    // odd
    else {
        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());
        return (double)a[n / 2];
    }
}
int cost (int n)
{
    int sum = 0;
    while(n>=0)
    {
        sum+=n;
        n--;
    }
    return sum;
}
int solution (const int median, const std::vector<int> horizontal_pos)
{
    auto lambda = [median](int a, int b){return a + cost(std::abs(b-median)); };
    return std::accumulate(horizontal_pos.begin(), horizontal_pos.end(), 0.0, lambda);
}

int main(int, char**) 
{
    std::ifstream myfile("/home/vicquecon/AoC/day_7/data.txt", std::ios_base::in);
    std::vector<int> horizontal_pos = {};
    std::string input;
    while (myfile >> input)
    {
        split(input,horizontal_pos);
    }
    // END PARSE
    int median = findMedian(horizontal_pos,horizontal_pos.size());
    int cost = solution(median,horizontal_pos);
    int it = 1;
    int cost_it = solution(median + it,horizontal_pos);
    if (cost_it - cost < 0)
    {
        std::cout<< "UP!"<<std::endl;
        while (cost_it < cost)
        {
            cost = cost_it;
            it++;
            cost_it = solution(median + it,horizontal_pos);
        }
    }
    it = -1;
    cost_it = solution(median + it,horizontal_pos);
    if (cost_it - cost < 0)
    {
        std::cout<< "DOWN!"<<std::endl;
        while (cost_it < cost)
        {
            cost = cost_it;
            it--;
            cost_it = solution(median + it,horizontal_pos);
        }
    }
    std::cout<< cost <<std::endl;
}
