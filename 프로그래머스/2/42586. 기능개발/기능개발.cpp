#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int SpendDay = 0;
    
    int progressesIndex = 0;
    while(progressesIndex < progresses.size())
    {
        int AnswerElement = 1;
        SpendDay = (100 - progresses[progressesIndex] - 1) / speeds[progressesIndex] + 1;
        
        progressesIndex++;
        while (progressesIndex < progresses.size() &&
               SpendDay >= (100 - progresses[progressesIndex] - 1) / speeds[progressesIndex] + 1)
        {
            AnswerElement++;
            progressesIndex++;
        }
        answer.emplace_back(AnswerElement);
    }
    return answer;
}