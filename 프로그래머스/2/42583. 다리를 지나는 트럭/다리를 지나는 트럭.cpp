#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<pair<int, int>> q;
    
    int NowWeight = 0;
    for (int Index = 0; Index < truck_weights.size(); Index++)
    {
        int TruckWeight = truck_weights[Index];
        
        while (!q.empty() && NowWeight + TruckWeight > weight)
        {
            auto Pair = q.front();
            q.pop();
            NowWeight -= Pair.first;
            if (answer < Pair.second)
            {
                answer = Pair.second;
            }
        }
        
        NowWeight += TruckWeight; 

        q.push({TruckWeight, answer + bridge_length});
        answer++;
    }
    
    return q.back().second;
}