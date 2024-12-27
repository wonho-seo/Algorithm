#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long castNum {static_cast<long long> (num)};
    while (castNum != 1){
        if (castNum % 2 == 0){
            castNum /= 2;
        } else {
            castNum = castNum * 3 + 1;
        }
        answer++;
        if (answer >= 500){
            return -1;
        }
    }
    return answer;
}