#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while (pq.top() < K) {
        answer++;

        if (pq.size() == 1 && pq.top() < K) {
            answer = -1;
            break;
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int new_food = first + (2 * second);
        pq.push(new_food);
    }

    return answer;
}
