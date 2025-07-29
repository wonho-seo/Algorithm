#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<pair<int, int>> Move = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
bool bValidRange(int Row, int Col, int MaxRow, int MaxCol)
{
    if (Row >= 0 && Row < MaxRow && Col >= 0 && Col < MaxCol)
    {
        return true;
    }
    return false;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    vector<vector<bool>> land_board(land.size(), vector<bool>(land[0].size(), false));
    vector<int> answer_board(land[0].size(), 0);
    queue<pair<int, int>> q;
    for (int row = 0; row < land.size(); ++row)
    {
        for (int col = 0; col < land[0].size(); ++col)
        {
            if (land[row][col] == 1 && !land_board[row][col])
            {
                int oil_count = 0;
                q.push({row, col});
                land_board[row][col] = true;
                set<int> answer_board_indexs;
                while(!q.empty())
                {
                    ++oil_count;

                    pair<int, int> current_pos = q.front();
                    q.pop();
                                        
                    answer_board_indexs.insert(current_pos.second);

                    for (const auto& [move_row, move_col] : Move)
                    {
                        int current_row = current_pos.first + move_row;
                        int current_col = current_pos.second + move_col;
                        if (bValidRange(current_row, current_col, land.size(), land[0].size()) && land[current_row][current_col] == 1 && !land_board[current_row][current_col])
                        {
                            q.push({current_row, current_col});
                            land_board[current_row][current_col] = true;
                        }
                    }
                }
                
                for(int index : answer_board_indexs)
                {
                    answer_board[index] += oil_count;
                }
            }
        }
    }
    
    for (int oil_count : answer_board)
    {
        answer = max(answer, oil_count);
    }
    return answer;
}