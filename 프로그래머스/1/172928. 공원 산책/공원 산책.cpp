#include <string>
#include <vector>

using namespace std;
bool bIsValiable(int NowRow, int NowCol, vector<vector<int>> ParkMap)
{
    if (NowRow < ParkMap.size() && NowCol < ParkMap[NowRow].size() && ParkMap[NowRow][NowCol] != 1)
    {
        return true;
    }
    return false;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<int>> ParkMap {park.size(), vector<int>(park[0].size(), 0)};
    int NowRow = 0;
    int NowCol = 0;
    for (int Row = 0; Row < park.size(); Row++)
    {
        for (int Col = 0; Col < park[Row].size(); Col++)
        {
            if (park[Row][Col] == 'S')
            {
                ParkMap[Row][Col] = 2;
                NowRow = Row;
                NowCol = Col;
            }
            else if(park[Row][Col] == 'X')
            {
                ParkMap[Row][Col] = 1;
            }
        }
    }
    
    for (int Index = 0; Index < routes.size(); Index++)
    {
        
        string route = routes[Index];
        int MoveRow = 0;
        int MoveCol = 0;
        if (route[0] == 'E')
        {
            MoveCol = route[2] - '0';
            for (int Col = 1; Col <= MoveCol; Col++)
            {
                if (!bIsValiable(NowRow, NowCol + Col, ParkMap))
                {
                    MoveCol = 0;
                    continue;
                }
            }
            NowCol += MoveCol;
        }
        else if (route[0] == 'S')
        {
            MoveRow = route[2] - '0';
            for (int Row = 1; Row <= MoveRow; Row++)
            {
                if (!bIsValiable(NowRow + Row, NowCol, ParkMap))
                {
                    MoveRow = 0;
                    continue;
                }
            }
            NowRow += MoveRow;
        }
        else if (route[0] == 'W')
        {            
            MoveCol = route[2] - '0';
            for (int Col = 1; Col <= MoveCol; Col++)
            {
                if (!bIsValiable(NowRow, NowCol - Col, ParkMap))
                {
                    MoveCol = 0;
                    continue;
                }
            }
            NowCol -= MoveCol;
        }
        else if (route[0] == 'N')
        {
            MoveRow = route[2] - '0';
            for (int Row = 1; Row <= MoveRow; Row++)
            {
                if (!bIsValiable(NowRow - Row, NowCol, ParkMap))
                {
                    MoveRow = 0;
                    continue;
                }
            }
            NowRow -= MoveRow;
        }
        
    }
    return {NowRow, NowCol};
}