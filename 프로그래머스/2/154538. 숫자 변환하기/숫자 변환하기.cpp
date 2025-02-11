#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;
using FuncPtr = int(*)(int, int);

int solution(int x, int y, int n) {
    vector<int> answer(y + 1 , numeric_limits<int>::max());
    vector<FuncPtr> Funcs;
    
    Funcs.push_back([](int a, int b){return a + b;});
    Funcs.push_back([](int a, int b){return a * 2;});
    Funcs.push_back([](int a, int b){return a * 3;});
    queue<int> q;
    
    answer[x] = 0;
    q.push(x);
    while (!q.empty() && x <= y + 1)
    {
        x = q.front();
        q.pop();
        int NextCount = answer[x] + 1;
        for (auto Func : Funcs)
        {
            int NextNum = Func(x, n);
            if (NextNum <= y && NextCount < answer[NextNum])
            {
                answer[NextNum] = NextCount;
                q.push(NextNum);
            }
        }
        
    }
    
    return answer[y] == numeric_limits<int>::max() ? -1 : answer[y];
}