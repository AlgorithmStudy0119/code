#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 우선순위 큐 less로 오름차순 정렬
    //priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> pque;
    priority_queue<vector<int>, vector<vector<int>>, compare> pque;
    int total_time = 0;
    int current_time = 0;
    int cnt = 0; // 작업 개수
    sort(jobs.begin(), jobs.end());

    // 소요시간 짧은 순으로 작업 수행
    while (!pque.empty() || cnt < jobs.size()) {
        // 요청시간이 현재 소요된 시간 보다 작을 때 작업 수행
        if (cnt < jobs.size() && jobs[cnt][0] <= current_time) {
            pque.push(jobs[cnt++]);
            continue;
        }
        // pque는 소요시간 적은순
        if (!pque.empty()) {
            // 소요시간 저장
            current_time += pque.top()[1];
            // 요청 시점 저장
            total_time += current_time - pque.top()[0];
            pque.pop();
        }
        else {
            // 다음 작업이 들어오는 시점으로 변경
            current_time = jobs[cnt][0];
        }
    }
    answer = total_time / jobs.size();
    return answer;
}