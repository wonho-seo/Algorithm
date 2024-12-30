#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    unsigned long flag { 1ul - s.size() % 2 };
    return s.substr(s.size() / 2 - flag, 1 + flag);
}