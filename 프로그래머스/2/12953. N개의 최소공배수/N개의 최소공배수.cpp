#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    for (int& a : arr)
    {
        answer = lcm(answer, a);
    }
    return answer;
}