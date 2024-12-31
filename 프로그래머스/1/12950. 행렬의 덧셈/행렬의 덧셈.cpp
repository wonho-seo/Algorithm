#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int colMax = arr1.size();
    int rowMax = arr1[0].size();
    for (int col = 0; col < colMax; col++){
        for (int row = 0; row < rowMax; row++){
            arr1[col][row] += arr2[col][row];
        }
    }
    
    return arr1;
}