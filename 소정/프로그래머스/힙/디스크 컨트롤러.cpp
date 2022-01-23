#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    //총 작업 시간
    int answer = 0;
    
    //작업 요청 시점 기준 오름차순 정렬
    sort(jobs.begin(), jobs.end());
    
    //job 번호, 현재 실행시간
    int idx = 0, time = 0;
    
    //작업 소요시간 기준 오름차순 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
    
    //남은 작업이 없고, 우선순위 큐가 빌때까지 반복
    while(idx < jobs.size() || !q.empty()){
        
        //현재 작업 처리 도중에 도착한 요청이 있는 경우
        if(idx < jobs.size() && jobs[idx][0] <= time){
            //(작업 소요시간, 작업 요청시간) 형식으로 큐에 추가
            q.push({ jobs[idx][1], jobs[idx][0] });
            idx++;
            continue;
        }
        
        //큐에 처리할 작업이 남은 경우
        if(!q.empty()){
            //현재 시간에 작업 소요시간 추가
            time += q.top().first;
            //총 작업 시간에 작업이 대기한 시간 추가
            answer += (time - q.top().second);
            q.pop();
        } 
        
        //큐가 비어있는 경우
        else {
            //다음 작업 시간으로 갱신
            time = jobs[idx][0];     
        }
    }
    
    return answer/jobs.size();  
}