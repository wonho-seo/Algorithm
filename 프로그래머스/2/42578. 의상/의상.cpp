#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> AnswerMap;
    for (vector<string> AClothes: clothes)
    {
        AnswerMap[AClothes[1]]++;
    }
    
    for (auto EachMap : AnswerMap)
    {
        answer *= EachMap.second + 1;
    }
    return answer - 1;
}