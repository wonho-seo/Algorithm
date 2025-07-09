#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> Moves {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

bool bIsValidRowCol(int Row, int Col, int MaxRow, int MaxCol)
{
    if (Row >= 0 && Row < MaxRow && Col >= 0 && Col < MaxCol)
    {
        return true;
    }
    return false;
}
int solution(vector<string> storage, vector<string> requests) {
    vector<vector<bool>> StorageCheckBoard (storage.size(), vector<bool>(storage[0].size(), false));
    
    for (string& Request : requests)
    {        
        vector<pair<int, int>> RemovedPositions;
        for (int Row = 0; Row < storage.size(); ++Row)
        {
            for (int Col = 0; Col < storage[0].size(); ++Col)
            {
                if (!StorageCheckBoard[Row][Col] && storage[Row][Col] == Request[0])
                {
                    if (Request.size() > 1)
                    {
                        StorageCheckBoard[Row][Col] = true;
                    }
                    else
                    {
                        queue<pair<int, int>> q;
                        vector<vector<bool>> VisitBoard (storage.size(), vector<bool>(storage[0].size(), false));
                        q.push({Row, Col});
                        while (!q.empty())
                        {
                            pair<int, int> CurrentPosition = q.front();
                            q.pop();
                            for (pair<int, int>& Move : Moves)
                            {
                                int NextRow = CurrentPosition.first + Move.first;
                                int NextCol = CurrentPosition.second + Move.second;
                                if (!bIsValidRowCol(NextRow, NextCol, StorageCheckBoard.size(), StorageCheckBoard[0].size())) 
                                {
                                    RemovedPositions.push_back({Row, Col});
                                    q = queue<pair<int,int>>();
                                    break;
                                }
                                else if(!VisitBoard[NextRow][NextCol] && StorageCheckBoard[NextRow][NextCol])
                                {
                                    q.push({NextRow, NextCol});
                                    VisitBoard[NextRow][NextCol] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (pair<int, int> RemovePosition : RemovedPositions)
        {
            StorageCheckBoard[RemovePosition.first][RemovePosition.second] = true;
        }
    }
    int answer = 0;
    for (vector<bool>& RowStorageCheckBoard : StorageCheckBoard)
    {
        for (bool EachStorageCheckBoard : RowStorageCheckBoard)
        {
            if (!EachStorageCheckBoard)
            {
                answer++;
            }
        }
    }
    return answer;
}
