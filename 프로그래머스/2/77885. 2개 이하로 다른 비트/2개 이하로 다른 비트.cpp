#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long number : numbers)
    {
        long long Shift = 1;
        for (int ShiftCount = 0; ShiftCount < 64; ShiftCount++)
        {
            if (!(Shift & number) || (Shift & number) && !((Shift << 1) & number))
            {
                answer.emplace_back(number + Shift);
                break;
            }
            Shift = Shift << 1;
        }
    }
    return answer;
}