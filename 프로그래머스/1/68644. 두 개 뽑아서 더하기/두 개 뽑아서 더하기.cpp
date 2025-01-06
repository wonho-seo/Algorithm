#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    for (int col = 0; col < numbers.size() - 1; col++){
        for (int row = col + 1; row < numbers.size(); row++){
            s.insert(numbers[col] + numbers[row]);
        }
    }
    
    return {s.begin(), s.end()};
}