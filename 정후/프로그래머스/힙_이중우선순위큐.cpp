#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> pq_asc;      // 오름차순
    priority_queue<int, vector<int>> pq_des;                    // 내림차순
    int cnt = 0;                                                // 큐 사이즈

    for (string o : operations) {

        if (!cnt) {             // 큐 비어있으면 오름, 내림 우선순위 큐 초기화
            while (!pq_asc.empty()) pq_asc.pop();
            while (!pq_des.empty()) pq_des.pop();
        }

        if (o[0] == 'I') {      // 삽입
            pq_des.push(stoi(o.substr(2)));
            pq_asc.push(stoi(o.substr(2)));
            cnt++;
        }
        else {
            if (!cnt) continue; // 큐 비어있으면 명령 무시
            
            if (o[2] == '1') {  // 최댓값 삭제
                pq_des.pop();
                cnt--;
            }   
            else {              // 최솟값 삭제
                pq_asc.pop();
                cnt--;
            }
        }
    }

    if (cnt) {
        answer.push_back(pq_des.top());
        answer.push_back(pq_asc.top());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
