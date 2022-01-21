#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;

    queue<pair<int,int>> q;
    priority_queue<int> priority_q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        priority_q.push(priorities[i]);
    }

    while (!q.empty()) {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();

        if (priority_q.top() == value) {
            priority_q.pop();
            count++;

            if (index == location) {
                answer = count;
                break;
            }
        }
        else
            q.push(make_pair(index, value));

    }

    return answer;
}
