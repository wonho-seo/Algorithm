#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int nowIndex = 0;
    
    for (int s : section){
        if(nowIndex < s){
            nowIndex = s + m - 1;
            answer++;
        }
    }
    
    return answer;
}