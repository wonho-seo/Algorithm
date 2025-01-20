#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    char StrOnce;
    int Index = 0;
    int CountX = 0;
    int CountNotX = 0;
    int answer = 0;
    
    for (const char& c : s)
    {
        if (Index == 0)
        {
            StrOnce = c;
        }
        
        if (c == StrOnce)
        {
            CountX++;
        }
        else
        {
            CountNotX++;
        }
        
        Index++;
        
        if (CountX == CountNotX)
        {
            answer++;
            Index = 0;
            CountX = 0;
            CountNotX = 0;
        }
    }
    if (Index != 0)
    {
        answer++;
    }
    return answer;
}