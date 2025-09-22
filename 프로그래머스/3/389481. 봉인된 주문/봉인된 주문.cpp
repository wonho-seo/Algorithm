#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long change_n(const string& str){
    long long n = 0;
    long long base = 1;

    for (int index = str.size() - 1; index >= 0; --index){
        n += base * (str[index] - 'a' + 1);

        base *= 26;
    }
    return n;
}

string n_toString(long long n){
    string str = "";
    
    while (n > 0){
        str += 'a' + (n - 1) % 26;
        n = (n - 1) / 26;
    }
    
    reverse(str.begin(), str.end());
    return str;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> BansNumber;
    
    for (string ban : bans){
        BansNumber.push_back(change_n(ban));
    }
    
    sort(BansNumber.begin(), BansNumber.end());

    for (const long long num : BansNumber){
        if (num <= n){
            n++;
        }
        else {
            break;
        }
    }
    
    return n_toString(n);
}