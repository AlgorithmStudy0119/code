#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {

    int total = 0, current = 0, cnt = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    sort(jobs.begin(), jobs.end()); // 요청시점 기준 오름차순 정렬

    while (cnt < jobs.size() || !pq.empty()) {

        if (cnt < jobs.size() && jobs[cnt][0] < current) {
            pq.push(jobs[cnt++]);
           
            continue;
        }

        if (!pq.empty()) {
            cnt += pq.top()[1];
            total += current - pq.top()[0];
            pq.pop();
        }
        else
            current = jobs[cnt][0];

    }

    return total / jobs.size();
}
