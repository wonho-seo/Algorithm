#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;
    stack<int> TempBelt;
    int NowBox = 1;
    int OrderIndex = 0;
    while (NowBox <= order.size())
    {
        int OrderBox = order[OrderIndex];
        if (OrderBox == NowBox)
        {
            answer++;
            NowBox++;
            OrderIndex++;
        }
        else if(!TempBelt.empty() && TempBelt.top() == OrderBox)
        {
            answer++;
            OrderIndex++;
            TempBelt.pop();
        }
        else
        {
            TempBelt.push(NowBox);
            NowBox++;
        }
    }
    while (!TempBelt.empty() && TempBelt.top() == order[OrderIndex])
    {
        answer++;
        OrderIndex++;
        TempBelt.pop();
    }
    return answer;
}