#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int StartIndex= sequence.size() - 1;
    int EndIndex = StartIndex;
    int Sum = sequence[StartIndex];
    vector<int> answer;
    while(StartIndex >= 0)
    {
        if (Sum == k)
        {
            if (answer.size() < 2 || answer[1] - answer[0] >= EndIndex - StartIndex)
            {
                answer = {StartIndex, EndIndex};
            }
            
            Sum -= sequence[EndIndex];
            EndIndex --;
        }
        else if (Sum > k)
        {
            Sum -= sequence[EndIndex];
            EndIndex--;
        }
        else
        {
            StartIndex--;
            Sum += sequence[StartIndex];
        }
    }
    
    return answer;
}