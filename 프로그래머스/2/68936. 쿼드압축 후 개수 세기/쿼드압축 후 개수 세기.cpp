#include <string>
#include <vector>

using namespace std;
vector<vector<int>> Arr;
pair<int, int> operator+=(pair<int, int>& p1, const pair<int, int>& p2)
{
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}
pair<int, int> dfs(int ColStart, int RowStart, int Length)
{
    if (Length <= 1)
    {
        return Arr[RowStart][ColStart] == 1 ? make_pair(0, 1) : make_pair(1, 0);
    }
    
    pair<int, int> SubAnswer {0, 0};
    int NextLength = Length / 2;
    SubAnswer += dfs(ColStart, RowStart, NextLength);
    SubAnswer += dfs(ColStart + NextLength, RowStart, NextLength);
    SubAnswer += dfs(ColStart, RowStart + NextLength, NextLength);
    SubAnswer += dfs(ColStart + NextLength, RowStart + NextLength, NextLength);
    
    if (SubAnswer.first == 0)
    {
        return {0, 1};
    }
    
    if (SubAnswer.second == 0)
    {
        return {1, 0};
    }
    return SubAnswer;
}

vector<int> solution(vector<vector<int>> arr) {
    Arr = arr;
    pair<int,int> answer = dfs(0, 0, arr.size());
    return {answer.first, answer.second};
}