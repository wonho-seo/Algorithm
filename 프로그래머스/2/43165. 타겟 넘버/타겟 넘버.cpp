#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, const int target, const int Sum, const int Index)
{
    if (Index >= numbers.size())
    {
        return Sum == target? 1 : 0;
    }
    
    return dfs(numbers, target, Sum + numbers[Index], Index + 1) + dfs(numbers, target, Sum - numbers[Index], Index + 1);
}
int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}