#include <string>
#include <vector>

using namespace std;

bool isInside(long long col, long long row, long long d)
{
    long long col_2 = col * col;
    long long row_2 = row * row;
    long long d_2 = d * d;
    return col_2 + row_2 <= d_2;
}

long long solution(int k, int d) {
    long long answer = 0;
    
    int col = 0;
    int row = d - d % k;
    
    while(row >= 0)
    {
        if (isInside(col, row , d))
        {
            answer += row / k + 1;
            col += k;
        }
        else
        {
            row -= k;
        }
    }
    return answer;
}