#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> ToppingMap1;
    map<int, int> ToppingMap2;
    for (int Index = 0; Index < topping.size(); Index++)
    {
        ToppingMap1[topping[Index]]++;
    }
    
    int answer = 0;
    for (int Index = 0; Index < topping.size() - 1; Index++)
    {
        int NowTopping = topping[Index];
        ToppingMap1[NowTopping]--;
        ToppingMap2[NowTopping]++;

        if (ToppingMap1[NowTopping] == 0)
        {
            ToppingMap1.erase(NowTopping);
        }
        
        if (ToppingMap2.size() == ToppingMap1.size())
        {
            answer++;
        }
    }
    return answer;
}