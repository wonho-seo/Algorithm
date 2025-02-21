#include <string>
#include <vector>

using namespace std;
using FuncPtr = bool(*)(int&, int&, int&, vector<int>&);
bool IsEmptySpace(vector<int>& answer, int Index)
{
    if (Index >= 0 && Index < answer.size() && answer[Index] == 0)
    {
        return true;
    }
    return false;
}

vector<int> solution(int n) {
    int MaxIndex = 0;
    for (int Index = 1; Index <= n; Index++)
    {
        MaxIndex += Index;
    }
    vector<int> answer(MaxIndex, 0);
    
    vector<FuncPtr> Funcs;
    
    Funcs.push_back([](int& Index, int& Col, int& Row, vector<int>& answer){
        int NextIndex = Index + Col + 1;
        if (NextIndex >= 0 && NextIndex < answer.size() && answer[NextIndex] == 0)
        {
            Col++;
            Index += Col;
            return true;
        }
        return false;
    });
    Funcs.push_back([](int& Index, int& Col, int& Row, vector<int>& answer){
        int NextIndex = Index + 1;
        if (NextIndex >= 0 && NextIndex < answer.size() && answer[NextIndex] == 0)
        {
            Row++;
            Index += 1;
            return true;
        }
        return false;
    });
    Funcs.push_back([](int& Index, int& Col, int& Row, vector<int>& answer){
        int NextIndex = Index - (Col + 1);
        if (NextIndex >= 0 && NextIndex < answer.size() && answer[NextIndex] == 0)
        {
            Col--;
            Index -= Col + 2;
            return true;
        }
        return false;
    });
    
    
    int Col = 0;
    int Row = 0;
    int AnswerIndex = 0;
    int FuncIndex = 0;
    answer[0] = 1;
    for (int Index = 1; Index < MaxIndex; Index++)
    {
        int FuncsCount = 0;
        while (!Funcs[FuncIndex](AnswerIndex, Col, Row, answer))
        {
            FuncIndex = (FuncIndex + 1) % Funcs.size();
            if (++FuncsCount > Funcs.size())
            {
                break;
            }
        }
        
        if (AnswerIndex >= 0 && AnswerIndex < answer.size())
        {
        answer[AnswerIndex] = Index + 1;
        }
    }
    return answer;
}