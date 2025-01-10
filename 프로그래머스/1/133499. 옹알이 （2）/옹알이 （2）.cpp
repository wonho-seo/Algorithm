#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const vector<string> pronounces {"aya", "ye", "woo", "ma"};

bool isSpeak(string& word)
{
    int index = 0;
    int flag = -1;
    while (index < word.size())
    { 
        bool isSpeak = false;
        for (int i = 0; i < pronounces.size(); i++){
            if (flag != i && word.find(pronounces[i], index) == index){
                index += pronounces[i].size();
                isSpeak =true;
                flag = i;
                break;
            }
        }
        
        if (!isSpeak){
            return false;
        }
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string& word : babbling){
        if (isSpeak(word)){
            answer++;        
        }
    }
    return answer;
}