#include <string>
#include <vector>

using namespace std;

int digitSum(int x);

bool solution(int x) {
    return x % digitSum(x) == 0 ? true : false;
}

int digitSum(int x){
    int digitSum {0};
    while(x > 0){
        digitSum += x % 10;
        x /= 10;
    }
    
    return digitSum;
}

