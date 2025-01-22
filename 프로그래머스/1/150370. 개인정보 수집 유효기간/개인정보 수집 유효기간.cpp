#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> split(const string& str, const string& delimit)
{
    vector<string> tokens;
    size_t start = 0;
    size_t end = str.find_first_of(delimit);
    
    while (end != string::npos)
    {
        if (end > start)
        {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
        end = str.find_first_of(delimit, start);
    }
    if (start < str.size())
    {
        tokens.push_back(str.substr(start));
    }
    
    return tokens;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    map<string, int> TermsMap;
    for (const string& term : terms)
    {
        vector<string> TermSplit = split(term, " ");
        string Condition = TermSplit[0];
        int TermNum = stoi(TermSplit[1]);
        TermsMap[Condition] = TermNum;
    }
    
    vector<string> TodayVector = split(today, ".");
    int TodayYear = stoi(TodayVector[0]);
    int TodayMonth = stoi(TodayVector[1]);
    int TodayDay= stoi(TodayVector[2]);
    
    vector<int> answer;
    for (int Index = 0; Index < privacies.size(); Index++)
    {
        vector<string> SplitPrivacy = split(privacies[Index], ". ");

        int Year = stoi(SplitPrivacy[0]);
        int Month = stoi(SplitPrivacy[1]);
        int Day = stoi(SplitPrivacy[2]);
        
        string Condition = SplitPrivacy[3];
        
        Month += TermsMap[Condition];
        
        int DiffYear = (TodayYear - Year);
        int DiffMonth = DiffYear * 12 + (TodayMonth - Month);
        
        if (DiffMonth > 0)
        {
            answer.emplace_back(Index + 1);
            
        }
        else if(DiffMonth == 0 && TodayDay - Day >= 0)
        {
            answer.emplace_back(Index + 1);
        }
    }
    return answer;
}