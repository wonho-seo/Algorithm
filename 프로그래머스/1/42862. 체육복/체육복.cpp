#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(31);
    for(int& l : lost)
    {
        student[l]--;
    }
    for (int& r : reserve)
    {
        student[r]++;
    }
    
    int answer = 0;
    for (int index = 1; index <= n; index++)
    {
        if (student[index] == -1)
        {
            if (student[index - 1] == 1)
            {
                student[index] = 0;
                student[index - 1] = 0;
            }
            else if(student[index + 1] == 1)
            {
                student[index] = 0;
                student[index + 1] = 0;
            }
        }
        
        if (student[index] >= 0) answer++;
    }
    
    return answer;
}