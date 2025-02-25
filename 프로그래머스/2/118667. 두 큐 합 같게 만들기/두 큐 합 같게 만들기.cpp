#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long q1Sum = 0;
    queue<int> q1;
    long q2Sum = 0;
    queue<int> q2;
    
    for (int q : queue1)
    {
        q1Sum += q;
        q1.push(q);
    }
    for (int q : queue2)
    {
        q2Sum += q;
        q2.push(q);
    }
    
    int answer = 0;
    int MaxAnswer = queue1.size() * 2 + 1;
    while (answer <= MaxAnswer)
    {
        if (q1Sum > q2Sum)
        {
            int Num = q1.front();
            q1.pop();
            q2.push(Num);
            
            q1Sum -= Num;
            q2Sum += Num;
        }
        else if(q1Sum < q2Sum)
        {
            int Num = q2.front();
            q2.pop();
            q1.push(Num);
            
            q2Sum -= Num;
            q1Sum += Num;
        }
        else
        {
            return answer;
        }
        answer++;
    }
    
    if (q1Sum == q2Sum)
    {
        return answer;
    }
    
    return -1;
}