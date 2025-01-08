#include <string>
#include <vector>
#include <map>
using namespace std;
const vector<vector<int>> people{ {1,2,3,4,5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3,3,1,1,2,2,4,4,5,5} };
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    map<int, int> m;
    for (int index = 0; index < 3; index++){
        m[index] = 0;
    }
    
    for (int index = 0; index < answers.size(); index++){
        for (int vectorIndex = 0; vectorIndex < people.size(); vectorIndex++){
            if (people[vectorIndex][index % people[vectorIndex].size()] == answers[index]){
                m[vectorIndex] ++;
            }
        }
    }
    
    int maxScore = 0;
    for (int vectorIndex = 0; vectorIndex < people.size(); vectorIndex++){
        maxScore = max(maxScore, m[vectorIndex]);
    }
    
    for (int vectorIndex = 0; vectorIndex < people.size(); vectorIndex++){
        int score = m[vectorIndex];
        if (maxScore == score){
            answer.emplace_back(vectorIndex + 1);
        }
    }
    return answer;
}