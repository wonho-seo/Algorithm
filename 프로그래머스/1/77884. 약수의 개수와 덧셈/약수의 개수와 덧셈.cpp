#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divisor(int n){
    int count {0};
    int maxIndex = static_cast<int>(sqrt(n));
    for (int index = 1; index < maxIndex; index++){
        if (count % index == 0){
            count += 2;
        }
    }
    
    if (maxIndex * maxIndex == n){
        count++;
    }
    
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    while (left <= right){
        if (divisor(left) % 2 == 0){
            answer += left;
        } else{
            answer -= left;
        }
        left++;
    }
    return answer;
}