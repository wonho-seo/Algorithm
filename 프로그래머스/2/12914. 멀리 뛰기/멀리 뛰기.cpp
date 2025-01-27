#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long Temp = 0;
    long long Before = 1;
    
    int answer = 1;
    for (int i = 2; i <= n; i++)
    {
        Temp = answer;
        answer += Before;
        answer %= 1234567;
        Before = Temp;
    }
    
    return answer;
}