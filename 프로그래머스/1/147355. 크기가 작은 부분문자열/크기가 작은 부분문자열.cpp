#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string_view t_view { t }, p_view{ p };
    for (int i = 0; i + p.size() <= t.size(); i++){
        string_view str { t_view.data() + i, p.size() };
        if (str <= p_view){
            answer++;
        }
    }
    return answer;
}