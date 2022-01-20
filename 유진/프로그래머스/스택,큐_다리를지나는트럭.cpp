#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> que;
    int time = 0;
    int sum = 0;
    int index = 0;

    while (true) {
        time++;
        // 트럭 도착 : 큐 크기 = 다리 길이
        if (que.size() == bridge_length) {
            sum -= que.front();
            que.pop();
        }
        // 트럭 무게 < 다리가 견딜수있는 무게 : 지나갈수 있으므로, 트럭 삽입
        if (sum + truck_weights[index] <= weight) {
            if (index == truck_weights.size() - 1) {
                // 마지막 트럭 도착시간 추가
                time += bridge_length;
                break;
            }
            que.push(truck_weights[index]);
            sum += truck_weights[index];
            index++;
        }
        // 트럭이 지나갈 수 없으면, 0 삽입해서 트럭을 도착지점으로 밈
        else {
            que.push(0);
        }
    }
    answer = time;
    return answer;
}