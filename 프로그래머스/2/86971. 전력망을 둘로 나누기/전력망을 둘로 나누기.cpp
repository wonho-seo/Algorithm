#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;
class Node
{
    public:
    int now;

    vector<Node*> Nexts;

    Node(int now) : now(now)
    {
    };

    void AddNext(Node* Next)
    {
        Nexts.push_back(Next);
    }
    
    int GetCount(int before)
    {
        int Count = 1;
        for (Node* N : Nexts)
        {
            if (N->now != before)
            {
                Count += N->GetCount(now);
            }
        }
        return Count;
    }
};

int solution(int n, vector<vector<int>> wires) {
    vector<unique_ptr<Node>> Nodes(n + 1);
    for (int Index = 1; Index <= n; Index++)
    {
        Nodes[Index] = make_unique<Node>(Index);
    }
    for (vector<int>& wire : wires)
    {
        Nodes[wire[0]]->AddNext(Nodes[wire[1]].get());
        
        Nodes[wire[1]]->AddNext(Nodes[wire[0]].get());
    }
    int answer = n;
    
    for (vector<int>& wire : wires)
    {
        answer = min(answer, abs(Nodes[wire[0]]->GetCount(wire[1]) - Nodes[wire[1]]->GetCount(wire[0])));
    }
    return answer;
}