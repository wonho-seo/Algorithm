#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intToVector(long long n);
long long vectorToInt(const vector<int> v);

long long solution(long long n) {
    vector<int> v {intToVector(n)};
    
    sort(v.begin(), v.end());  
    
    return vectorToInt(v);
}

vector<int> intToVector(long long n){
    vector<int> v;
    while (n > 0){
        v.push_back(n % 10);
        n /= 10;
    }
    
    return v;
}
long long vectorToInt(const vector<int> v){
    long long answer = 0;
    for (int index {static_cast<int>(v.size()) - 1}; index >= 0; index--){
        answer *= 10;
        answer += v[index];
    }
    return answer;
}