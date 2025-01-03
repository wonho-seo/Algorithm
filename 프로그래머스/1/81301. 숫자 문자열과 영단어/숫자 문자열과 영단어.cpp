#include <string>
#include <vector>
#include <regex>

using namespace std;
const vector<string> stringNums {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void replace_all(string& s, string_view from, string_view to){
    size_t pos {0};
    while ((pos = s.find(from, pos)) != string::npos){
        s.replace(pos, from.length(), to);
        pos += to.length() - 1;
    }
}
int solution(string s) {
    for(int pos = 0; pos < stringNums.size(); pos++){
        replace_all(s, stringNums[pos], to_string(pos));
    }
    return stoi(s);
}