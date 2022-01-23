#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++){
        int temp = 100 - progresses[i];
        if(temp % speeds[i]==0) q.push(temp / speeds[i]);
        else q.push(temp/speeds[i] + 1);
    }
    
    while(!q.empty()){
        int cnt = 1;
        int now = q.front();
        q.pop();
        while(1){
            if(!q.empty() && now >= q.front()){
                cnt++;
                q.pop();
            } else {
                answer.push_back(cnt);
                break;
            }
        }
    }
    return answer;
}