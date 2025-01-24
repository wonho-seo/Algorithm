#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    int StringStart = 0;
    int StringEnd = s.find_first_of(" ");
    
    while (StringEnd != string::npos)
    {
        s[StringStart] = toupper(s[StringStart]);
        for (int Index = StringStart + 1; Index < StringEnd; Index++)
        {
            s[Index] = tolower(s[Index]);
        }
        
        StringStart = StringEnd + 1;
        StringEnd = s.find_first_of(" ", StringStart);
    }
    
    if (StringStart < s.size())
    {
        s[StringStart] = toupper(s[StringStart]);
        for (int Index = StringStart + 1; Index < s.size(); Index++)
        {
            s[Index] = tolower(s[Index]);
        }
    }
    
    return s;
}