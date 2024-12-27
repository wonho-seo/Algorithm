#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int index {1}; index < n; index++){
        if (n % index == 1){
            return index;
        }
    }
}