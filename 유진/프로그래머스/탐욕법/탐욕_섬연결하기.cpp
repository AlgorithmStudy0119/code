#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int check = 0;
    sort(costs.begin(), costs.end(), comp);

    int parent[n];
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    // 거리 작은 순으로 삽입
    for (int i = 0; i < costs.size(); ++i) {
        if (parent[costs[i][0]] != parent[costs[i][1]]) {
            if (parent[costs[i][0]] > parent[costs[i][1]]) {
                int tmp1 = parent[costs[i][0]];
                int tmp2 = parent[costs[i][1]];
                for (int j = 0; j < n; ++j) {
                    if (parent[j] == tmp1)
                        parent[j] = tmp2;
                }
            }
            else {
                int tmp1 = parent[costs[i][1]];
                int tmp2 = parent[costs[i][0]];
                for (int j = 0; j < n; ++j) {
                    if (parent[j] == tmp1)
                        parent[j] = tmp2;
                }
            }
            answer += costs[i][2];
            check++;
        }
        if (check == n - 1)
            break;
    }

    return answer;
}