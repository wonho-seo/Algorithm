#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>

using namespace std;
vector<string> split(string str)
{
    int end = str.find_first_of(" ");
    
    return {str.substr(0, end), str.substr(end + 1)};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, unique_ptr<unordered_set<string>>> ReportMap;
    unordered_map<string, int> ReportCount;
    for (const string& id : id_list)
    {
        ReportMap[id] = make_unique<unordered_set<string>>();
    }
    
    
    for (const string& r : report)
    {
        vector<string> SplitReport = split(r);
        unordered_set<string>& ReportSet = *ReportMap[SplitReport[0]].get();
        
        if (ReportSet.find(SplitReport[1]) == ReportSet.end())
        {
            ReportMap[SplitReport[0]]->insert(SplitReport[1]);
            ReportCount[SplitReport[1]]++;
        }
    }
    
    for(const string& id: id_list)
    {
        unordered_set<string>& ReportSet = *ReportMap[id].get();
        int Count = 0;
        for (const string& r : ReportSet)
        {
        
            if (ReportCount[r] >= k)
            {
                Count++;
            }
        }
        answer.emplace_back(Count);
    }
    
    return answer;
}