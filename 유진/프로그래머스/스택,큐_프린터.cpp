#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que; // 인덱스, 중요도 저장 큐
    priority_queue <int> pque; // 중요도 정렬
    for (int i = 0;i < priorities.size();i++) {
        que.push({ i,priorities[i] });
        pque.push(priorities[i]);
    }

    while (!que.empty() && !pque.empty()) {
        if (que.front().second == pque.top()) { // 현재 작업의 중요도 == 가장 중요한 것
            answer++;
            if (que.front().first == location) { // 인덱스 == location
                return answer;
            }
            que.pop();
            pque.pop();
        }
        else {
            // que.front를 que에 다시 삽입
            pair<int, int> tmp = { que.front().first, que.front().second };
            que.pop();
            que.push(tmp);
        }
    }

    return answer;
}