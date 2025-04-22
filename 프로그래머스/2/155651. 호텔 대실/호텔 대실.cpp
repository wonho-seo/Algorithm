#include <queue>
#include <vector>
#include <ostream>

using namespace std;

int TimeStringToTimeSec(string str)
{
    int Minute = stoi(str.substr(0, 2));
    int Seconds = stoi(str.substr(3, 2));
    
    return Minute * 60 + Seconds;
}

int solution(vector<vector<string>> book_time) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> BookTimeQueue;
    priority_queue<int, vector<int>, greater<int>> EndBookTimeQueue;

    for (vector<string> BT : book_time)
    {
        BookTimeQueue.push(pair<int, int>(TimeStringToTimeSec(BT[0]), TimeStringToTimeSec(BT[1]) + 10));
    }

    int TimeSec = 0;
    int answer = 0;
    while (!BookTimeQueue.empty())
    {
        pair<int, int> CurrentBook = BookTimeQueue.top();
        BookTimeQueue.pop();
        
        EndBookTimeQueue.push(CurrentBook.second);
        TimeSec = CurrentBook.first;
        
        if (TimeSec >= EndBookTimeQueue.top())
        {
            while (TimeSec >= EndBookTimeQueue.top())
            EndBookTimeQueue.pop();
        }
        else
        {
            answer = max<int>(answer, EndBookTimeQueue.size());
        }
    }
    
    return answer;
}