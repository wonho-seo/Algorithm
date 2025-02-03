#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int FindAnswer(int StartIndex, int EndIndex, vector<int> citations)
{
    for (int Index = StartIndex; Index <= EndIndex; Index++)
    {
        if (citations[Index] >= citations.size() - Index)
        {
            return citations.size() - Index;
        }
    }
}

int dfs(int StartIndex, int EndIndex, vector<int> citations)
{
    int pivot = (StartIndex + EndIndex) / 2;
    
    if (EndIndex - StartIndex < 10)
    {
        return FindAnswer(StartIndex, EndIndex, citations);
    }
    if (citations[pivot] <= citations.size() - pivot)
    {
        return dfs(pivot + 1, EndIndex, citations);
    }
    else
    {
        return dfs(StartIndex, pivot - 1, citations);
    }
}
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    return dfs(0, citations.size() - 1, citations);
}