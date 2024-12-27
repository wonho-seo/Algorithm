#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int maxNum {static_cast<int>(sqrt(n))};
    for(int index {1}; index <= maxNum; index++){
        if (n % index == 0){
            answer = answer + index + n / index;
        }
    }
    
    if (maxNum * maxNum == n){
        answer -= maxNum;
    }
    
    return answer;
}