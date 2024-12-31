#include <string>
#include <vector>
#include <regex>

using namespace std;

bool solution(string s) {
    regex reg {"^\\d{4}$|^\\d{6}$"};
    return regex_match(s, reg);
}