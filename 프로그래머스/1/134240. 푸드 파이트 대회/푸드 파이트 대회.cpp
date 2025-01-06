#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<int> food) {
    stringstream ss;
    
    for (int index = 1; index < food.size(); index++){
        for (int amount = 0; amount < food[index] / 2; amount++){
            ss << index;
        }
    }
    ss << "0";
    string answer;
    ss >> answer;
    answer += {answer.rbegin() + 1, answer.rend()};
    
    return answer;
}