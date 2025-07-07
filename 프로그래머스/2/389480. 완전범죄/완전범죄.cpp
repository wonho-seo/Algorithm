#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int member_n;
int member_m;
int dfs(const vector<vector<int>>& infos, vector<vector<vector<int>>>& dp, int Index, int cost_a, int cost_b)
{
    if (cost_a >= member_n || cost_b >= member_m)
    {
        return numeric_limits<int>::max();
    }
    
    if (Index == infos.size())
    {
        return cost_a;
    }
    
    if (dp[Index][cost_a][cost_b] != -2)
    {
        return dp[Index][cost_a][cost_b];
    }
    
    const vector<int>& info = infos[Index];
    
    int answer = dfs(infos, dp, Index + 1, cost_a + info[0], cost_b);
    answer = min(answer, dfs(infos, dp, Index + 1, cost_a, cost_b + info[1]));

    dp[Index][cost_a][cost_b] = answer;
    
    return answer;
}
    
int solution(vector<vector<int>> info, int n, int m) {
    member_n = n;
    member_m = m;
    vector<vector<vector<int>>> dp (info.size(),
        vector<vector<int>>(n,
            vector<int>(m, -2)
            )
    );
    int answer = dfs(info, dp, 0, 0, 0);
    if (answer == numeric_limits<int>::max())
    {
        answer = -1;
    }
    return answer;
}