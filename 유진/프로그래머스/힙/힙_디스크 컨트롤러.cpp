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
    // �켱���� ť less�� �������� ����
    //priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> pque;
    priority_queue<vector<int>, vector<vector<int>>, compare> pque;
    int total_time = 0;
    int current_time = 0;
    int cnt = 0; // �۾� ����
    sort(jobs.begin(), jobs.end());

    // �ҿ�ð� ª�� ������ �۾� ����
    while (!pque.empty() || cnt < jobs.size()) {
        // ��û�ð��� ���� �ҿ�� �ð� ���� ���� �� �۾� ����
        if (cnt < jobs.size() && jobs[cnt][0] <= current_time) {
            pque.push(jobs[cnt++]);
            continue;
        }
        // pque�� �ҿ�ð� ������
        if (!pque.empty()) {
            // �ҿ�ð� ����
            current_time += pque.top()[1];
            // ��û ���� ����
            total_time += current_time - pque.top()[0];
            pque.pop();
        }
        else {
            // ���� �۾��� ������ �������� ����
            current_time = jobs[cnt][0];
        }
    }
    answer = total_time / jobs.size();
    return answer;
}