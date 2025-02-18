#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

set<int> CreatedNumbers;
bool IsPrime(int num)
{
    if (num < 2)
    {
        return false;

    }
    int MaxIndex = static_cast<int>(sqrt(num));
    for (int Index = 2; Index <= MaxIndex; Index++)
    {
        if (num % Index == 0)
        {
            return false;
        }
    }
    
    return true;
}

void dfs(string& numbers, int Index, string NowNumbers)
{
    if (Index >= numbers.size())
    {
        return;
    }
    dfs(numbers, Index + 1, NowNumbers);
    for (int I = 0; I <=NowNumbers.size(); I++)
    {
        string str = NowNumbers.substr(0, I) + numbers[Index] + NowNumbers.substr(I);

        CreatedNumbers.insert(stoi(str));
        dfs(numbers, Index + 1, str);
    }
    
    string str = numbers[Index] + NowNumbers;
    
    CreatedNumbers.insert(stoi(str));
    dfs(numbers, Index + 1, str);
}

int solution(string numbers) {
    int answer = 0;
    
    dfs(numbers, 0, "");
    for (int Num : CreatedNumbers)
    {
        if (IsPrime(Num))
        {
            answer++;
        }
    }
    return answer;
}