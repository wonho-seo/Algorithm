#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), std::greater<char>());
    return s;
}