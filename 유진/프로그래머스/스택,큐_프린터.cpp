#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que; // �ε���, �߿䵵 ���� ť
    priority_queue <int> pque; // �߿䵵 ����
    for (int i = 0;i < priorities.size();i++) {
        que.push({ i,priorities[i] });
        pque.push(priorities[i]);
    }

    while (!que.empty() && !pque.empty()) {
        if (que.front().second == pque.top()) { // ���� �۾��� �߿䵵 == ���� �߿��� ��
            answer++;
            if (que.front().first == location) { // �ε��� == location
                return answer;
            }
            que.pop();
            pque.pop();
        }
        else {
            // que.front�� que�� �ٽ� ����
            pair<int, int> tmp = { que.front().first, que.front().second };
            que.pop();
            que.push(tmp);
        }
    }

    return answer;
}