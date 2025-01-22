#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> PlayerToRankMap;
    unordered_map<int, string> RankToPlayerMap;
    for(int Index = 0; Index < players.size(); Index++)
    {
        PlayerToRankMap[players[Index]] = Index + 1;
        RankToPlayerMap[Index + 1] = players[Index];
    }
    
    for (const string& calling : callings)
    {
        int CallingRank = PlayerToRankMap[calling];
        string FrontPlayer = RankToPlayerMap[CallingRank - 1];
        PlayerToRankMap[calling]--;
        PlayerToRankMap[FrontPlayer]++;
        RankToPlayerMap[CallingRank - 1] = RankToPlayerMap[CallingRank];
        RankToPlayerMap[CallingRank] = FrontPlayer; 
    }
    
    vector<string> answer;
    answer.reserve(players.size());
    
    for (int Rank = 1; Rank <= players.size(); Rank++)
    {
        answer.push_back(RankToPlayerMap[Rank]);
    }
    return answer;
}