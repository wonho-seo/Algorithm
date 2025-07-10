#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    
    vector<bool> mask(n, false);
    fill(mask.begin() + (n-5), mask.end(), true);
    
    int answer = 0;
    
    do {
        vector<int> candidate;
        for (int index = 0; index < n; ++index)
        {
            if (mask[index])
            {
                candidate.push_back(nums[index]);
            }
        }
        
        for (int index = 0; index < q.size(); index++)
        {
            vector<int>& each_q = q[index];
            vector<int> intersection;
            set_intersection(each_q.begin(), each_q.end(),
                             candidate.begin(), candidate.end(),
                             back_inserter(intersection));
            if (intersection.size() != ans[index])
            {
                answer--;
                break;
            }
        }
        answer++;
    }
    while(next_permutation(mask.begin(), mask.end()));
    
    
    return answer;
}