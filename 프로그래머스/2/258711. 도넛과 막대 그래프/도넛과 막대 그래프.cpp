#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    int MaxNodeIndex = 0;
    for (vector<int> edge : edges)
    {
        MaxNodeIndex = max(MaxNodeIndex, max(edge[0], edge[1]));
    }
    vector<pair<int, int>> Board (MaxNodeIndex + 1, pair{0, 0});
    
    for (vector<int> edge : edges)
    {
        Board[edge[0]].first++;
        Board[edge[1]].second++;
    }

    for (int Index = 1; Index < Board.size(); ++Index)
    {
        pair<int, int> Node = Board[Index];
        if (Node.first > 1 && Node.second == 0)
        {
            answer[0] = Index;
        }
        else if(Node.first == 0 && Node.second > 0)
        {
            answer[2]++;
        }
        else if(Node.first > 1 && Node.second > 1)
        {
            answer[3]++;
        }
        
    }
    
    answer[1] = Board[answer[0]].first - answer[2] - answer[3];
    return answer;
}