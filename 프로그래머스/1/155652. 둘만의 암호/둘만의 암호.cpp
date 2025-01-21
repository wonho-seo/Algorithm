#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool IsSkipChar(char c, string skip)
{
    for (const char& SkipChar : skip)
    {
        if (c == SkipChar)
        {
             return true;   
        }
    }
    return false;
}

int FindIndexByChar(const char c, vector<char>& vec)
{
    for (int index = 0; index < vec.size(); index++)
    {
        if (vec[index] == c)
            return index;
    }
    return vec.size();
}

string solution(string s, string skip, int index) {
    vector<char> ChangeCharList(26 - skip.size());
    int ChangeCharListIndex = 0;
    for(int Index = 0; Index < 26; Index++)
    {
        char c = static_cast<char>(static_cast<int>('a') + Index);
        
        if (!IsSkipChar(c, skip))
        {
            ChangeCharList[ChangeCharListIndex] = c;
            ChangeCharListIndex++;
        }
    }
    
    for (char& SChar : s)
    {
        int ChangeCharIndex = FindIndexByChar(SChar, ChangeCharList);
        
        char ChangeChar = ChangeCharList[(ChangeCharIndex + index) % ChangeCharList.size()];
        SChar = ChangeChar;
    }
    return s;
}

