#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    
    for (int priority : priorities)
    {
        pq.push(priority);
    }
    
    int Index = 0; 
    int answer = 1;
    while (!pq.empty())
    {
        if (priorities[Index] == pq.top())
        {
            if (Index == location)
            {
                return answer;
            }
            answer++;
            pq.pop();
        }
        Index = Index + 1 == priorities.size() ? 0 : Index + 1;
    }
}