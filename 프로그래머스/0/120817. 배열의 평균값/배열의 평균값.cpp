#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    return static_cast<double>(accumulate(numbers.begin(), numbers.end(), 0)) / static_cast<double>(numbers.size());
}