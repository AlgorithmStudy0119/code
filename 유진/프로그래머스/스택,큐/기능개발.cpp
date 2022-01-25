#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> pro;
    vector<int> spe;
    // 남은 작업 속도
    for(int i=0;i<progresses.size();i++){
        pro.push_back(100 - progresses[i]);
    }
    // 배포까지 걸리는 시간
    for(int i=0;i<speeds.size();i++){
        int tmp = 0;
        if(pro[i] % speeds[i] == 0){
            tmp = pro[i] / speeds[i];
        }
        else{
            tmp = pro[i] / speeds[i] + 1;
        }
        spe.push_back(tmp);
    }
    // for(int i=0;i<spe.size();i++){
    //     cout << spe[i] << " ";
    // }
    
    queue<int> que;
    // spe가 que front보다 작으면, 큐에 삽입
    que.push(spe[0]);
    for(int i=1;i<spe.size();i++){
        if(que.front() >= spe[i]){ 
            que.push(spe[i]);
        }
        else{
            // 큐에 있는 배포 가능한 개수 answer에 삽입
            answer.push_back(que.size());
            // 큐 비우기
            while(!que.empty())
                que.pop();
            que.push(spe[i]);
        }
    }
    
    if(!que.empty())
        answer.push_back(que.size());
    
    return answer;
}
