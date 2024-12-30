#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minElement {INT_MAX};
    int minIndex {0};
    
    for (int index {0}; index < arr.size(); index++){
        if (minElement > arr[index]){
            minElement = arr[index];
            minIndex = index;
        }
    }
    
    arr.erase(arr.begin() + minIndex);
    
    if (arr.size() == 0){
        arr.push_back(-1);
    }
    return arr;
}