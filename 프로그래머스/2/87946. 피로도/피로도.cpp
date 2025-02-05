#include <string>
#include <vector>

using namespace std;
int dfs(int k, const vector<vector<int>>& dungeons,vector<int> DungeonVisit, int deep)
{
    int answer = 0;
    for (int Index = 0; Index < DungeonVisit.size(); Index++)
    {
        if (DungeonVisit[Index] == 0 && k >= dungeons[Index][0])
        {
            DungeonVisit[Index] = 1;
            answer = max(answer, 1 + dfs(k - dungeons[Index][1], dungeons, DungeonVisit, deep + 1));
            DungeonVisit[Index] = 0;
        }
    }
    return answer;
}
int solution(int k, vector<vector<int>> dungeons) {
    vector<int> DungeonVisit(dungeons.size(), 0);
    return dfs(k, dungeons, DungeonVisit, 0);
}