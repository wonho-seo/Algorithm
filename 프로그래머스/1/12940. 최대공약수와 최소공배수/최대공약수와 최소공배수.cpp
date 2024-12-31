#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}
vector<int> solution(int n, int m) {
    int nmGcd = gcd(n, m); 
    return {nmGcd , n * m / nmGcd};
}