#include <string>
#include <vector>
#include <bitset>

using namespace std;

int CountOneByString(const string& str)
{
    int Count = 0;
    for (const char& c : str)
    {
        if (c == '1')
        {
            Count++;
        }
    }
    return Count;
}

vector<int> solution(string s) {
    int TotalCountChange = 0;
    int TotalCountZero = 0;
    
    while (s.size() != 1)
    {
        int CountOne = CountOneByString(s);
        TotalCountChange++;
        TotalCountZero += s.size() - CountOne;
        
        bitset<32> binary(CountOne);
        s = binary.to_string();
        s.erase(0, s.find_first_not_of('0'));
    }
    return {TotalCountChange, TotalCountZero};
}