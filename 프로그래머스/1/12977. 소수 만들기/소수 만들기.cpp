#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num){
    for (int index = 2; index <= static_cast<int>(sqrt(num)); index++){
        if (num % index == 0){
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for (int index1 = 0; index1 < nums.size() - 2; index1++){
        for (int index2 = index1 + 1; index2 < nums.size() - 1; index2++){
            for (int index3 = index2 + 1; index3 <nums.size(); index3++){
                if (isPrime(nums[index1] + nums[index2] + nums[index3])){
                    answer++;
                }
            }
        }
    }
    return answer;
}