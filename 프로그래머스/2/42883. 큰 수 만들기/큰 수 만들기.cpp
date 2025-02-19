#include <string>
#include <list>
using namespace std;

string solution(string number, int k) {
    list<int> ls;
    int DeleteCount = k;
    for (int Index = 0; Index < number.size(); Index++)
    {
        while (DeleteCount > 0 &&!ls.empty() && ls.back() < number[Index])
        {
            ls.pop_back();
            DeleteCount--;
        }
        ls.push_back(number[Index]);
    }
    
    
    return string(ls.begin(), prev(ls.end(), DeleteCount));
}