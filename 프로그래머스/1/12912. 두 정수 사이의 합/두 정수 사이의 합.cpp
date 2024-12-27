#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int minIndex {min(a, b)};
    int maxIndex {max(a, b)};
    for (; minIndex <= maxIndex; minIndex++){
        answer += minIndex;
    }
    return answer;
}