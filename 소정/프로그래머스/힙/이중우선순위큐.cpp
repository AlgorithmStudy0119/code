#include <string>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    //오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> q1;
    //내림차순 우선순위 큐
    priority_queue<int, vector<int>, less<int>> q2;
    
    //큐에 들어있는 값 개수
    int cnt = 0;
    
    for(string op : operations){
        if(cnt == 0){
            while(!q1.empty())  q1.pop();
            while(!q2.empty())  q2.pop();
        }
        
        //숫자 삽입
        if( op[0] == 'I'){
            q1.push(stoi(op.substr(2)));
            q2.push(stoi(op.substr(2)));
            cnt++;
        }
        
        else{
            if(cnt==0)  continue;
            
            //최댓값 삭제
            if(op[2] == '1'){
                q2.pop();
                cnt--;
            }
            //최솟값 삭제
            else{
                q1.pop();
                cnt--;
            }
        }
    }
    
    if(cnt==0){
        answer.push_back(0);
        answer.push_back(0);
    } else{
        answer.push_back(q2.top());
        answer.push_back(q1.top());
    }
    
    return answer;
}