#include <iostream>
#include <vector>
using namespace std;
#define MAX_TIME 500001

void SetRoadPath(vector<vector<int>>& RoadPath, int StartNode, int SpendTime)
{    
    for (int StartNodeIndex = 1; StartNodeIndex < RoadPath.size(); ++StartNodeIndex)
    {
        if (SpendTime + RoadPath[StartNode][StartNodeIndex] < RoadPath[1][StartNodeIndex])
        {
            RoadPath[1][StartNodeIndex] = SpendTime + RoadPath[StartNode][StartNodeIndex];
            SetRoadPath(RoadPath, StartNodeIndex, RoadPath[1][StartNodeIndex]);
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<int>> RoadPath(N + 1, vector<int>(N + 1,MAX_TIME));
    
    for (vector<int>& r : road)
    {
        if (RoadPath[r[0]][r[1]] > r[2])
        {
            RoadPath[r[0]][r[1]] = r[2];
            RoadPath[r[1]][r[0]] = r[2];
        }
    }

    for (int StartNodeIndex = 1; StartNodeIndex < RoadPath.size(); ++StartNodeIndex)
    {
        if (RoadPath[1][StartNodeIndex] < MAX_TIME)
        {
            SetRoadPath(RoadPath, StartNodeIndex, RoadPath[1][StartNodeIndex]);
        }
    }
    
    int answer = 0;
    for (int& Time : RoadPath[1])
    {
        if (Time <= K)
        {
            answer++;
        }
    }

    if (RoadPath[1][1] > K)
    {
        answer++;
    }
    return answer;
}