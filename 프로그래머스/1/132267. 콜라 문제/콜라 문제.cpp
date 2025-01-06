#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int remainder = 0;
    
    while (n > 0){
        n += remainder;
        remainder = n % a;
        n = n / a * b;
        answer += n;
    }
    
    return answer;
}