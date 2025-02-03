#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool IsZeroMap(const vector<string>& want, unordered_map<string, int>& WantMap)
{
    for (string w : want)
    {
        if (WantMap[w] != 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> WantMap;
    for (int Index = 0; Index < want.size(); Index++)
    {
        WantMap[want[Index]] = number[Index];
    }
    for (int Index = 0; Index < 10; Index++)
    {
        if (WantMap.find(discount[Index]) != WantMap.end())
        {
            WantMap[discount[Index]]--;
        }
    }
    
    int answer = 0;
    if (IsZeroMap(want, WantMap))
    {
        answer++;
    }
    
    for(int Index = 0; Index + 10 < discount.size(); Index++)
    {
        if (WantMap.find(discount[Index]) != WantMap.end())
        {
            WantMap[discount[Index]]++;
        }
        
        if (WantMap.find(discount[Index + 10]) != WantMap.end())
        {
            WantMap[discount[Index + 10]]--;
        }
        
        if (IsZeroMap(want, WantMap))
        {
            answer++;
        }
    }
    return answer;
}