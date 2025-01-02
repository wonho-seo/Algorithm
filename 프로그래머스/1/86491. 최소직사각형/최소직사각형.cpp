#include <string>
#include <vector>
#include <limits>

using namespace std;

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int solution(vector<vector<int>> sizes) {
    int maxCol {numeric_limits<int>::min()};
    int maxRow {numeric_limits<int>::min()};
    
    for (auto size : sizes){
        if (size[0] > size[1]){
            swap(size[0], size[1]);
        }
        
        maxCol = max(maxCol, size[0]);
        maxRow = max(maxRow, size[1]);
    }
    
    return maxCol * maxRow;
}