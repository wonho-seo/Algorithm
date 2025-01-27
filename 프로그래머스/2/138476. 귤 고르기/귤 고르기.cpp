#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> FruitMap;
    
    for (const int& t : tangerine)
    {
        FruitMap[t]++;
    }
    
    vector<int> FruitVec (FruitMap.size());

    int Index =0;
    
    for (auto F : FruitMap)
    {
        FruitVec[Index] = F.second;
        Index++;
    }
    
    sort(FruitVec.begin(), FruitVec.end(), greater<int>());
    int answer = 0;

    while (k > 0)
    {
        k -= FruitVec[answer];
        answer++;
    }
    
    return answer;
}