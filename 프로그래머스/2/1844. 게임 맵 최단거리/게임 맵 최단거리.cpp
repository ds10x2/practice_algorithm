#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int d[4][2] = {{1, 0}, {-1,0}, {0, 1}, {0, -1}};
    
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    //초기 위치
    q.push({1,{0,0}});
    visited[0][0] = true;
    
    while(!q.empty() && answer == -1){
        
        int move = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        for(int idx = 0; idx < 4; idx++){
            int nx = x + d[idx][0];
            int ny = y + d[idx][1];
            
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
            if(visited[nx][ny]) continue;
            if(maps[nx][ny] == 0) continue;
            
            if(nx == maps.size()-1 && ny == maps[0].size() - 1){
                answer = move+1;
                break;
            }
            
            q.push({move+1, {nx, ny}});
            visited[nx][ny] = true;
        }
        
    }
    
    
    
    return answer;
}