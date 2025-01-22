#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux = numeric_limits<int>::max();
    int luy = numeric_limits<int>::max();
    int rdx = 0;
    int rdy = 0;
    
    for (int row = 0; row < wallpaper.size(); row++)
    {
        for (int col = 0; col < wallpaper[row].size(); col++)
        {
            if (wallpaper[row][col] == '#')
            {
                lux = min(lux, row);
                luy = min(luy, col);
                rdx = max(rdx, row);
                rdy = max(rdy, col);
            }
        }
    }
    return {lux, luy, rdx + 1, rdy + 1};
}