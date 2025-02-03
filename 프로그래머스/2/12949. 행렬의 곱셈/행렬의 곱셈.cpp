#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int Arr1Col = 0; Arr1Col < arr1.size(); Arr1Col++)
    {
        vector<int> AnswerCol;
        for (int Arr2Row = 0; Arr2Row < arr2[0].size(); Arr2Row++)
        {
            int answerElement = 0;
            for (int Arr1Row = 0; Arr1Row < arr1[0].size(); Arr1Row++)
            {
                answerElement += arr1[Arr1Col][Arr1Row] * arr2[Arr1Row][Arr2Row];
            }
            AnswerCol.emplace_back(answerElement);
        }
        answer.push_back(AnswerCol);
    }
    return answer;
}