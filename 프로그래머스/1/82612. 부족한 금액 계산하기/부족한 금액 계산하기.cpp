using namespace std;

long long solution(int price, int money, int count)
{
    long long answer { 0 };
    
    for (int index { 1 }; index <= count; index++){
        answer += index;
    }
    
    answer = answer * price - money;
    return answer > 0 ? answer : 0;
}