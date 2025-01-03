#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](string a, string b){
        return b[n] != a[n] ? a[n] < b[n] : b > a;
    });
    
    return strings;
}