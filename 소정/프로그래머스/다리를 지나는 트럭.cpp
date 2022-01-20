#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;     //시간
    int curWeight = 0;  //현재 다리 위에 있는 트럭들의 무게 
    int idx = 0;        //트럭 번호
    queue<int> q;       //다리 위에 있는 트럭 리스트
    
    while(1){
        answer++;
        
        //트럭이 도착한 경우, 무게 빼주고 제거 
        if(q.size() == bridge_length){
            curWeight -= q.front();
            q.pop();
        }
        //트럭 추가 시 다리 견딜수 있는 무게 안넘으면 추가
        if(curWeight + truck_weights[idx] <= weight){
            //마지막 트럭일 경우
            if(idx == truck_weights.size() - 1){
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[idx]);
            curWeight += truck_weights[idx];
            idx++;
        }
        //트럭 추가 못하면 0으로 트럭 밀어줌
        else{
            q.push(0);
        }
    }

    return answer;
}