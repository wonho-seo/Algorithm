#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> ToNumberSystem(int n, int k)
{
    vector<string> ResultVector;
    vector<char> result;
    int StringLength = 0;
    while (n > 0)
    {
        int NumElement = n % k;
        if (NumElement == 0)
        {
            if (result.size() > 0)
            {
                ResultVector.push_back(string(result.rbegin(), result.rend()));
                result.clear();
            }
        }
        else
        {
            result.push_back('0' + NumElement);
        }
        n /= k;
    }
    if (result.size() > 0)
    {
        ResultVector.push_back(string(result.rbegin(), result.rend()));
    }
    
    return ResultVector;
}

bool isPrime(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    vector<string> Number = ToNumberSystem(n, k);
    int answer = 0;
    for (string s : Number)
    {
        if (isPrime(stoll(s)))
        {
            answer++;
        }
    }
    return answer;
}