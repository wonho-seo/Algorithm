#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string str (phone_number.size() - 4, '*');
    return phone_number.replace(0, phone_number.size() - 4, str);
}