#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


//k: 한 상자에 담으려는 귤의 개수
// tangerine: 귤의 크기 벡터
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> tangerine_size;
    
    for(int idx = 0; idx < tangerine.size(); idx++){
        tangerine_size[tangerine[idx]]++;
    }
    
   
    priority_queue<int> q;
    
    for(auto itr = tangerine_size.begin(); itr != tangerine_size.end(); itr++) {
       q.push(itr->second);
    }

    
    int temp = 0;
    int idx = 0;
    while(temp < k){
        temp += q.top();
        idx++;
        q.pop();
    }
    
    return idx;
}