#include "numeric"

using namespace std;

long long solution(int w,int h) {
    int gcdWH = gcd(w, h);
    return static_cast<long long>(w) * h  - (static_cast<long long>(w) + h - gcdWH);
}