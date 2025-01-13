#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int>    getVector(string X)
{
    vector<int> temp (10,0);
    
    for (const char& c: X)
    {
        temp[c - '0']++;
    }
    return temp;
}

string solution(string X, string Y) {
    vector<int> vectorX = getVector(X);
    vector<int> vectorY = getVector(Y);
    
    stringstream ss;
    for (int index = 9; index > 0; index--)
    {
        while(vectorX[index] > 0 && vectorY[index] > 0)
        {
            ss << to_string(index);
            vectorX[index]--;
            vectorY[index]--;
        }
    }
    
    if (ss.str().empty())
    {
        if (vectorX[0] > 0 && vectorY[0] > 0)
        {
            return "0";
        } 
        else
        {
            return "-1";
        }
    }
    
    while(vectorX[0] > 0 && vectorY[0] > 0)
    {
        ss << to_string(0);
        vectorX[0]--;
        vectorY[0]--;
    }
    
    return ss.str();
}