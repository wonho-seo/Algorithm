#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0)
    {
        int digit = storey % 10;
        if (digit > 5)
        {
            storey += 10;
            answer += (10 - digit);
        }
        else if (digit == 5)
        {
            int NextDigit = (storey / 10) % 10;
            if (NextDigit > 4)
            {
                storey += 10;
            }
            answer += digit;
        }
        else 
        {        
            answer += digit;
        }
        
        storey /= 10;
    }
    
    return answer;
}