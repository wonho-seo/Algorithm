#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (char& c : s){
        if (c == ' '){
            index = 0;
            continue;
        }
        if (index % 2 == 0){
            c = toupper(c);
        } else{
            c = tolower(c);
        }
        index++;
    }
    return s;
}