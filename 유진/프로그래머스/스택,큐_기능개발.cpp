#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> pro;
    vector<int> spe;
    // ���� �۾� �ӵ�
    for(int i=0;i<progresses.size();i++){
        pro.push_back(100 - progresses[i]);
    }
    // �������� �ɸ��� �ð�
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
    // spe�� que front���� ������, ť�� ����
    que.push(spe[0]);
    for(int i=1;i<spe.size();i++){
        if(que.front() >= spe[i]){ 
            que.push(spe[i]);
        }
        else{
            // ť�� �ִ� ���� ������ ���� answer�� ����
            answer.push_back(que.size());
            // ť ����
            while(!que.empty())
                que.pop();
            que.push(spe[i]);
        }
    }
    
    if(!que.empty())
        answer.push_back(que.size());
    
    return answer;
}