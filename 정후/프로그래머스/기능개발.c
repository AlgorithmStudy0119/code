#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    int size = progresses.size();

    for (int i = 0; i < size; i++) {

        int day = (100 - progresses[i]) / speeds[i];

        if ((100 - progresses[i]) % speeds[i] != 0) {
            day++;
        }

        q.push(day);
    }

    while (q.size()) {
        
        int count = 1;
        
        int front = q.front();
        q.pop();

        while (q.size() && front >= q.front()) {
            count++;
            q.pop();
        }

        answer.push_back(count);
    }

    return answer;
}
