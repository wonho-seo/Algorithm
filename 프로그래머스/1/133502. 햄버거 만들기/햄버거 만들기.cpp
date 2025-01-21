#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> Temp {0};
    int answer = 0;
    for (int I : ingredient)
    {
        if (Temp.back() == 1 && I == 2)
        {
            Temp.back() = 12;
        }
        else if(Temp.back() == 12 && I == 3)
        {
            Temp.back() = 123;
        }
        else if(Temp.back() == 123 && I == 1)
        {
            answer++;
            Temp.pop_back();
        }
        else
        {
            Temp.emplace_back(I);
        }
    }
    return answer;
}