#include <string>
#include <vector>

using namespace std;

const pair<int, int> getHitCount(const vector<int>& lottos, const vector<int>& win_nums){
    int hitCount = 0;
    int zeroCount = 0;
    for (int lotto : lottos){
        if (lotto != 0){
            for (int win_num : win_nums){
                if (lotto == win_num){
                    hitCount++;
                }
            }    
        } else {
            zeroCount++;
        }
    }
    
    return {hitCount, zeroCount};
}

const int determineLottoRank(const int hitCount){
    int rank = 7 - hitCount ;
    if (rank > 6){
        rank = 6;
    }
    return rank;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    pair<int, int> hitCount = getHitCount(lottos, win_nums);
    
    return {determineLottoRank(hitCount.first + hitCount.second), determineLottoRank(hitCount.first)};
}