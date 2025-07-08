#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server_count (players.size(), 0);
    
    int current_server = 0;
    
    for (int time = 0; time < players.size(); ++time)
    {
        if (time - k >= 0)
        {
            current_server -= server_count[time - k];
        }
        
        int required_server = players[time] / m - current_server;

        if (required_server > 0)
        {
            server_count[time] = required_server;
            answer += required_server;
            current_server += required_server;
        }
    }
    return answer;
}