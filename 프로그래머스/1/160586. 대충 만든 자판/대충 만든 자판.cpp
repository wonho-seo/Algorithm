#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> MinPushCount (25, 0);
    vector<int> answer;
    
    for (string key : keymap)
    {
        for (int index = 0; index < key.size(); index++)
        {
            int KeyIndex = key[index] - static_cast<int>('A');
            if (MinPushCount[KeyIndex] == 0 || MinPushCount[KeyIndex] > index + 1)
            {            
                MinPushCount[KeyIndex] = index + 1;
            }
        }
    }
    
    
    for (string target : targets)
    {
        int PushCount = 0;
        for (int Index = 0; Index < target.size(); Index++)
        {
            if(MinPushCount[target[Index] - static_cast<int>('A')] == 0)
            {
                PushCount = -1;
                break;
            }
            else
            {
                PushCount += MinPushCount[target[Index] - static_cast<int>('A')];
            }
        }
        
        answer.emplace_back(PushCount);
        
    }
    return answer;
}