#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, idx = 0, sum = 0;
    queue<int> q;

    while (1) {
        if (idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }

        answer++;
        int temp = truck_weights[idx];

        if (q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }

        if (sum + temp <= weight) {
            sum += temp;
            q.push(temp);
            idx++;
        }
        else
            q.push(0);

    }

    return answer;
}
