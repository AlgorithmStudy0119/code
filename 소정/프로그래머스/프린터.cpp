#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //문서의 <위치, 중요도> 저장
    queue<pair<int,int>> q; 
    
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
    }
    
    sort(priorities.begin(), priorities.end());
    
    while(!priorities.empty()){
        //문서 중 가장 높은 중요도
        int highest = priorities.back();
        pair<int, int> temp;
        
        while(1){
            //현재 문서가 가장 높은 중요도이면
            if(q.front().second == highest){
                answer++;
                if(q.front().first == location)
                    return answer;
                q.pop();
                break;
            }
            //대기 목록에 더 중요도가 높은 문서가 있는 경우
            else{
                temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        priorities.pop_back();
    }
    
    return answer;
}