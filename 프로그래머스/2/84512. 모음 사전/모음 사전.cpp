#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string word) {
    vector<char> Alpa = {'A', 'E', 'I', 'O', 'U'};
    stack<int> ShiftNumbers;
    ShiftNumbers.push(1);
    
    for (int Index = 1; Index < 5; Index++)
    {
        int ShiftNumber = ShiftNumbers.top() * 5 + 1;
        ShiftNumbers.push(ShiftNumber);
    }
    int answer = word.size();
    for (const char& c : word)
    {
        answer += distance(Alpa.begin(), find(Alpa.begin(), Alpa.end(), c)) * ShiftNumbers.top();
        ShiftNumbers.pop();
    }
    return answer;
}
    