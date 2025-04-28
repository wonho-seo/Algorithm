#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int getGcd(vector<int> array)
{
    int primeNum = array[0];
    for (int index = 1; index < array.size(); index++)
    {
        primeNum = gcd(primeNum, array[index]);
    }
    return primeNum;
}

bool isNonPrime(vector<int> array, int prime)
{
    for (int a : array)
    {
        if (a % prime == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> getPrimes(int gcd)
{
    vector<int> primes;
    for (int index = 2; index * index <= gcd; index++)
    {
        if (gcd % index == 0)
        {
            primes.push_back(index);
        }
    }
    primes.push_back(gcd);
    return primes;
}

int getMaxPrime(vector<int> array, vector<int> primes)
{
    for (int primesIndex = primes.size() - 1; primesIndex >= 0; primesIndex--)
    {
        if (isNonPrime(array, primes[primesIndex]))
        {
            return primes[primesIndex];
        }
    }
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    vector<int> PrimesA = getPrimes(getGcd(arrayA));
    vector<int> PrimesB = getPrimes(getGcd(arrayB));
    
    return max(getMaxPrime(arrayA, PrimesB), getMaxPrime(arrayB, PrimesA));
}