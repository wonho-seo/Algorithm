#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    for (int Index = 0; Index < survey.size(); Index++)
    {
        int choice = choices[Index];
        if (choice < 4)
        {
            m[survey[Index][0]] += 4 - choice;
        }
        else if (choice > 4)
        {
            m[survey[Index][1]] += choice - 4;
        }
    }
    
    if (m['R'] >= m['T'])
    {
        answer += 'R';
    }
    else 
    {
        answer += 'T';
    }
    
    if (m['F'] > m['C'])
    {
        answer += 'F';
    }
    else
    {
        answer += 'C';
    }
    
    if (m['J'] >= m['M'])
    {
        answer += 'J';
    }
    else
    {
        answer += 'M';
    }
    
    if (m['A'] >= m['N'])
    {
        answer += 'A';
    }
    else
    {
        answer += 'N';
    }
    return answer;
}