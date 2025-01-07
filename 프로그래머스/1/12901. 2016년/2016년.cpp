#include <string>
#include <vector>

using namespace std;
const vector<string> week {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
const vector<int> monthDay{ 31, 29, 31, 30, 31,30,31,31,30,31,30,31};

string solution(int a, int b) {
    int diffDay = 0;
    for (int month = 0; month < a - 1; month++){
        diffDay += monthDay[month];
    }
    diffDay += b - 1;
    
    return week[diffDay % 7];
}