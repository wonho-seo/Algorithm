#include <string>
#include <vector>
#include <map>

#define CAR_IN_STRING "IN"
#define CAR_OUT_STRING "OUT"
#define RECORDS_DELIMITER_STRING " "
#define TIME_DELIMITER_STRING ":"
#define TIME_END_STRING "23:59"
using namespace std;

vector<string> GetSplitString(const string& str, const string& Delimiter)
{
    vector<string> SplitString;
    size_t StartIndex = 0;
    size_t EndIndex = str.find(Delimiter);
    while (EndIndex != string::npos)
    {
    SplitString.push_back(str.substr(StartIndex, EndIndex - StartIndex));
        StartIndex = EndIndex + 1;
        EndIndex = str.find(Delimiter, StartIndex);
    }
    SplitString.push_back(str.substr(StartIndex));
    return SplitString;
}
vector<vector<string>> GetSplitRecords(const vector<string>& recordes,const string& Delimiter)
{
    vector<vector<string>> SplitRecordes;
    for (const string& recorde : recordes)
    {
        SplitRecordes.push_back(GetSplitString(recorde, Delimiter));
    }
    return SplitRecordes;
}

int GetTimeMinDiff(const string& TimeIn,const string& TimeOut)
{
    if (TimeIn == "" || TimeOut == "")
    {
        return 0;
    }
    vector<string> SplitTimeIn = GetSplitString(TimeIn, TIME_DELIMITER_STRING);
    vector<string> SplitTimeOut = GetSplitString(TimeOut, TIME_DELIMITER_STRING);
    
    return (stoi(SplitTimeOut[0]) - stoi(SplitTimeIn[0])) * 60 + stoi(SplitTimeOut[1]) - stoi(SplitTimeIn[1]);
}

int GetFee(vector<int>& fees, int TimeMin)
{
    int OverTime = TimeMin - fees[0];
    if (OverTime <= 0)
    {
        return fees[1];
    }
    return fees[1] + (1 + (OverTime - 1) / fees[2]) * fees[3];
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<vector<string>> SplitRecordes = GetSplitRecords(records, RECORDS_DELIMITER_STRING);
    map<string, pair<int, string>> CarReports;
    
    for (const vector<string>& SplitRecord: SplitRecordes)
    {
        if (SplitRecord[2] == CAR_OUT_STRING)
        {
            pair<int, string>& CarReport = CarReports[SplitRecord[1]];
            CarReport.first += GetTimeMinDiff(CarReport.second, SplitRecord[0]);
            CarReport.second.clear();
        }
        else if (SplitRecord[2] == CAR_IN_STRING)
        {
            pair<int, string>& CarReport = CarReports[SplitRecord[1]];
            CarReport.second = SplitRecord[0];
        }
    }
    
    vector<int> answer;
    for (auto& CarReportMap : CarReports)
    {
        pair<int, string>& CarReport = CarReportMap.second;
        if (CarReport.second != "")
        {
            CarReport.first += GetTimeMinDiff(CarReport.second, TIME_END_STRING);
        }
        answer.emplace_back(GetFee(fees, CarReport.first));
    }
    return answer;
}