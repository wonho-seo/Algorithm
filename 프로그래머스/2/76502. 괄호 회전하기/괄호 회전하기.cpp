#include <string>
#include <vector>
#include <list>

using namespace std;

bool CorrectChar(char c1, char c2)
{
    if (c1 == '[' && c2 == ']')
    {
        return true;
    }
        
    if (c1 == '(' && c2 == ')')
    {
        return true;
    }
    
    if (c1 == '{' && c2 == '}')
    {
        return true;
    }
        
    return false;
}

int solution(string s) {
  
    int answer = 0;
    for (int SpinIndex = 0; SpinIndex < s.size(); SpinIndex++)
    {  
        list<char> StringList;
        for(int Index = 0; Index < s.size(); Index++)
        {
            char c = s[(Index + SpinIndex) % s.size()];
            if(StringList.empty())
            {
                StringList.push_back(c);
                continue;
            }
            if (CorrectChar(StringList.back(), c))
            {
                StringList.pop_back();
            }
            else
            {
                StringList.push_back(c);
            }
        }
        
        if (StringList.size() == 0)
        {
            answer++;
        }
    }
    return answer;
}