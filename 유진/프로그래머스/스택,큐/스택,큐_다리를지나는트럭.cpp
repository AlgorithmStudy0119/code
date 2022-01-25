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
        // Ʈ�� ���� : ť ũ�� = �ٸ� ����
        if (que.size() == bridge_length) {
            sum -= que.front();
            que.pop();
        }
        // Ʈ�� ���� < �ٸ��� �ߵ����ִ� ���� : �������� �����Ƿ�, Ʈ�� ����
        if (sum + truck_weights[index] <= weight) {
            if (index == truck_weights.size() - 1) {
                // ������ Ʈ�� �����ð� �߰�
                time += bridge_length;
                break;
            }
            que.push(truck_weights[index]);
            sum += truck_weights[index];
            index++;
        }
        // Ʈ���� ������ �� ������, 0 �����ؼ� Ʈ���� ������������ ��
        else {
            que.push(0);
        }
    }
    answer = time;
    return answer;
}