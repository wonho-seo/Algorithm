#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int MultiAnswer = brown + yellow;
    int SumAnswer = (brown + 4) / 2;
    int Discriminant = sqrt(SumAnswer * SumAnswer - 4 * MultiAnswer);
    
    return {(SumAnswer + Discriminant) / 2, (SumAnswer - Discriminant) / 2};
}