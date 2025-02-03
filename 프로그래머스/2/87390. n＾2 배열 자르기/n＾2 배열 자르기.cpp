#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answerArr;
    for (long long Index = left; Index <= right; Index++)
    {
        int answer = max(Index / n, Index % n) + 1;
        answerArr.emplace_back(answer);
    }
    return answerArr;
}