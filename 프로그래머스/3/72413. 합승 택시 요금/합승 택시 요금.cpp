#include <string>
#include <vector>
#include <numeric>
using namespace std;

#define INT_MAX numeric_limits<int>::max()
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    for (int index = 1; index <= n; ++index){
        dp[index][index] = 0;
    }
    for(const vector<int>& fare : fares){
        dp[fare[0]][fare[1]] = fare[2];
        dp[fare[1]][fare[0]] = fare[2];
    }
    
    for(int mid = 1; mid <= n; ++mid){
        for(int col = 1; col <= n; ++col){
            for (int row = 1; row <= n; ++row){
                if (dp[mid][row] != INT_MAX && dp[col][mid] != INT_MAX){                
                    dp[col][row] = min(dp[col][row], dp[col][mid] + dp[mid][row]);
                }
            }
        }
    }
    
    
    int answer = INT_MAX;
    for (int pos_mid = 1; pos_mid <= n; ++pos_mid){
        if (dp[s][pos_mid] != INT_MAX && dp[pos_mid][a] != INT_MAX && dp[pos_mid][b] != INT_MAX){
            answer = min(answer, dp[s][pos_mid] + dp[pos_mid][a] + dp[pos_mid][b]);
        }
    }
    return answer;
}