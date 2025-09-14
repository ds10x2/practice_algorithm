#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    vector<int> timeline(24, 0);
    
    for(int idx = 0; idx < 24; idx++){
        if(players[idx] >= (timeline[idx] + 1) * m){
            int temp = players[idx] / m - timeline[idx];
            answer += temp;
            for(int k_idx = 0; k_idx < k; k_idx++){
                if(idx + k_idx >= 24) break;
                timeline[idx + k_idx] += temp;
            }
        }
    }
    
    
    return answer;
}