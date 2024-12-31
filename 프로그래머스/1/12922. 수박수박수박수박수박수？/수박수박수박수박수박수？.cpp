#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(int n) {
    stringstream ss;
    int strCount = n / 2;
    for (int i = 0 ; i < strCount; i++){
        ss << "수박";
    }
    if (n % 2 == 1){
        ss << "수";
    }
    
    return ss.str();
}