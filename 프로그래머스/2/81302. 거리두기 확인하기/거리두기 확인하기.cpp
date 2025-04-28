#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX_RANGE 5

bool InsidePlace(int col, int row)
{
    if (col >= 0 && col < MAX_RANGE && row >= 0 && row < MAX_RANGE)
    {
        return true;
    }
    return false;
}

vector<pair<int, int>> moves = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

int IsAnswer(const vector<string>& place)
{
    for (int col = 0; col < 5; col++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (place[col][row] == 'P')
            {
                queue<pair<pair<int, int>, int>> q;
                q.push({{col, row}, 0});
                // 깊이부족, q의 갯수만셈
                int count = 0;
                while(!q.empty())
                {
                    pair<int, int> CurrentLocation = q.front().first;
                    count = q.front().second;
                    q.pop();
                    if (count > 1)
                    {
                        continue;
                    }
                    
                    for (pair<int, int> move : moves)
                    {
                        pair<int, int> NextLocation = {CurrentLocation.first + move.first, CurrentLocation.second + move.second};
                        if (InsidePlace(NextLocation.first, NextLocation.second) &&
                           NextLocation != pair{col, row})
                        {
                            if (place[NextLocation.first][NextLocation.second] == 'P')
                            {
                                return 0;
                            }
                            else if(place[NextLocation.first][NextLocation.second] != 'X')
                            {
                                q.push({NextLocation, count + 1});
                            }
                        }
                    }
                    count++;
                }
            }
        }
    }
    return 1;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (const vector<string>& place : places)
    {
        answer.push_back(IsAnswer(place));
    }
    return answer;
}