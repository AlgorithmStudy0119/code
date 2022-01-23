#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    //최소 조합 횟수
    int answer = 0;
    
    //오름차순 우선순위 큐
    priority_queue<int,vector<int>, greater<int>> q;    
    int min1, min2;
    
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    //음식이 2개 이상이고, 스코빌 지수가 k보다 작을 때동안 반복
    while(q.size()>1 && q.top() < K){
        
        //음식 2개 꺼내서 섞고 큐에 추가
        min1 = q.top();
        q.pop();
        min2 = q.top();
        q.pop();
        q.push(min1 + 2*min2);
        
        answer++;
    }
    
    //모든 조합이 끝났을 때 우선순위 큐의 제일 맵지 않은 음식이 K보다 작으면 -1 리턴
    if(q.top()<K)   return -1;
    return answer;
}
