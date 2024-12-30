#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer {0};
    
    for (int index = 0; index < absolutes.size(); index++){
        signs[index] == true ? answer += absolutes[index] : answer -= absolutes[index];
    }
    
    return answer;
}