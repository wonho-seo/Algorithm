#include <string>
#include <vector>

using namespace std;


string solution(string s) {
    size_t Start = 0;
    size_t End = s.find_first_of(" ");
    
    long Min = numeric_limits<long>::max();
    long Max = numeric_limits<long>::min();
    while (End != string::npos)
    {
        long Num = stol(s.substr(Start, End));
        Min = min(Min, Num);
        Max = max(Max, Num);
        
        Start = End + 1;
        End = s.find_first_of(" ", Start);
    }
    
    if (Start < s.size())
    {
        long Num = stol(s.substr(Start));
        Min = min(Min, Num);
        Max = max(Max, Num);
    }
    return to_string(Min) + " " + to_string(Max);
}