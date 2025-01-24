#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int FristF = 0;
    int SecondF = 1;
    
    for (int Index = 2; Index < n; Index++)
    {
        int ThirdF = (FristF + SecondF) % 1234567;
        FristF = SecondF;
        SecondF = ThirdF;
    }
    return (FristF + SecondF) % 1234567;
}