#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> ElementsSumSet;
    
    for (int Index = 0; Index < elements.size(); Index++)
    {
        int SumElements = 0;
        for (int NextIndex = 0; NextIndex < elements.size(); NextIndex++)
        {
            SumElements += elements[(Index + NextIndex) % elements.size()];
            ElementsSumSet.insert(SumElements);
        }
    }
    return ElementsSumSet.size();
}