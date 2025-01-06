#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    map<char, int> map;
    vector<int> answer;
    
    for (int index = 0; index < s.size(); index++){
        char c = s[index];
        if(map.find(c) != map.end()){
            answer.emplace_back(index - map[c]);
        } 
        else{
            answer.emplace_back(-1);
        }
        map[c] = index;
    }
    
    return answer;
}