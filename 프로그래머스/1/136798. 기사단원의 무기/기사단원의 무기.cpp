#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getDivisor(int number){
    int divisor = 1;
    int sqrtNumber = sqrt(number);
    for (int num = 2; num <= sqrtNumber; num++){
        if (number % num == 0){
            divisor++;
        }
    }
    
    return number == sqrtNumber * sqrtNumber ? divisor * 2 - 1 : divisor * 2;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int num = 1; num <= number; num ++){
        int divisor = getDivisor(num);
        answer += divisor > limit ? power : divisor;
    }
    return answer;
}