#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<pair<int,int>> get_all_pos(vector<int>& start_points, vector<int>& end_points)
{
    vector<pair<int, int>> all_pos;
    pair<int, int> current_pos = {start_points[0], start_points[1]};
    all_pos.push_back(current_pos);
    
    pair<int, int> move = {end_points[0] - start_points[0], end_points[1] - start_points[1]};
    
    for (int row = 0; row < abs(move.first); ++row)
    {
        current_pos.first += move.first > 0 ? 1 : -1;
        all_pos.push_back(current_pos);
    }
    
    for (int col = 0; col < abs(move.second); ++col)
    {
        current_pos.second += move.second > 0 ? 1 : -1;
        all_pos.push_back(current_pos);
    }
    return all_pos;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> run_logs;
    for (vector<int>& route : routes)
    {
        vector<pair<int,int>> each_logs;
        for (int index = 1; index < route.size(); ++index)
        {
            vector<pair<int,int>> tmp_logs = get_all_pos(points[route[index - 1] - 1], points[route[index] - 1]);
            if (index > 1)
            {
                each_logs.insert(each_logs.end(),tmp_logs.begin() + 1, tmp_logs.end());
            }
            else
            {
                each_logs.insert(each_logs.end(),tmp_logs.begin(), tmp_logs.end());

            }
        }
         run_logs.push_back(each_logs);
    }
    
    int max_time = 0;
    for(auto& run_log : run_logs)
    {
        max_time = max(max_time, static_cast<int>(run_log.size()));
    }
    
    for (int time = 0; time < max_time; time++)
    {
        map<pair<int, int>, int> reports;

        for(auto& run_log : run_logs)
        {
            if (time < run_log.size())
            {
                ++reports[run_log[time]];
            }
        }
        
        for (auto& report : reports)
        {
            if (report.second > 1)
            {
                answer++;
            }
        }
    }
    return answer;
}