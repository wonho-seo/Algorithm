#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> copy2dVector(vector<int> vec){
    vector<int> copyVec (vec);
    
    return copyVec;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int index = 0; index < commands.size(); index++){
        auto copyArray = copy2dVector(array);
        sort(copyArray.begin() + commands[index][0] - 1, copyArray.begin() + commands[index][1]);
        answer.emplace_back(copyArray[commands[index][0] + commands[index][2] - 2]);
    }
    return answer;
}