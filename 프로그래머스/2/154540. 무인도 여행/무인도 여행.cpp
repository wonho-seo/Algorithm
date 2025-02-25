#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> Move = { {1,0}, {-1,0}, {0, 1}, {0, -1}};
bool IsValidZone(int Col, int Row, int MaxCol, int MaxRow)
{
    if (Col >= 0 && Row >=0 && Col < MaxCol && Row < MaxRow)
    {
        return true;
    }
    return false;
}
vector<int> solution(vector<string> maps) {
    vector<vector<bool>> VisitMap(maps.size(), vector<bool>(maps[0].size(), false));
    vector<int> answer;
    
    for (int Col = 0; Col < maps.size(); Col++)
    {
        string& map = maps[Col];
        for (int Row = 0; Row < map.size(); Row++)
        {
            if (map[Row] != 'X' && !VisitMap[Col][Row])
            {
                int Sum = map[Row] - '0';
                VisitMap[Col][Row] = true;
                queue<vector<int>> q;
                q.push({Col, Row});
                while (!q.empty())
                {
                    vector<int>& FrontQ = q.front();
                    int NCol = FrontQ[0];
                    int NRow = FrontQ[1];
                    q.pop();
                    for (vector<int>& M : Move)
                    {
                        int NowCol = NCol + M[0];
                        int NowRow = NRow + M[1];
                        if (IsValidZone(NowCol, NowRow, maps.size(), map.size()) &&
                            maps[NowCol][NowRow] != 'X' &&
                            !VisitMap[NowCol][NowRow])
                        {
                            VisitMap[NowCol][NowRow] = true;
                            Sum += maps[NowCol][NowRow] - '0';
                            q.push({NowCol, NowRow});
                        }
                    }
                }
                answer.push_back(Sum);
            }
        }
        
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    return answer;
}