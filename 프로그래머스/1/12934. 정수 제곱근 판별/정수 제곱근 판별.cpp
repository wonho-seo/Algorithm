#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long sqrtN = static_cast<long long>(sqrt(n));
    return sqrtN * sqrtN == n ? (sqrtN + 1) * (sqrtN + 1) : -1;
}