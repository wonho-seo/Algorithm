#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer {0};
    for (int num : numbers){
        answer += num;
    }
    return 45 - answer;
}