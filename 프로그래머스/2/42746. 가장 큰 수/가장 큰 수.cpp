#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> StrNumbers;
    for (int number : numbers)
    {
        StrNumbers.push_back(to_string(number));
    }
    sort(StrNumbers.begin(), StrNumbers.end(),[](string str1, string str2){
        return str1 + str2 > str2 + str1;
    });
    
    if (StrNumbers[0] == "0")
    {
        return "0";
    }
    stringstream ss;
    for (string str : StrNumbers)
    {    
        ss << str;
    }
    
    return ss.str();
}