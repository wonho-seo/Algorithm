#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> BigNumbers;
    BigNumbers.push(-1);
    
    for (int Index = numbers.size() - 1; Index >= 0; Index--)
    {
        int BigNumber = BigNumbers.top();
        while (BigNumber != -1 && numbers[Index] >= BigNumber)
        {
            BigNumbers.pop();
            BigNumber= BigNumbers.top();
        }
        BigNumbers.push(numbers[Index]);
        numbers[Index] = BigNumber;
    }
    return numbers;
}