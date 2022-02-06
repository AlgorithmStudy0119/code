#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int current, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& cnt, queue<int>& que) {
    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int i = 0;i < graph[node].size();i++) {
            if (!visited[graph[node][i]]) {
                int current = cnt[node] + 1;
                visited[graph[node][i]] = true;
                cnt[graph[node][i]] = current;
                que.push(graph[node][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    vector<int> cnt(n + 1, 0);
    vector<bool> visited(n + 1, false);
    //vector<int> vec;
    queue<int> que;

    // 양방향 그래프 생성
    for (int i = 0;i < edge.size();i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    que.push(1);
    visited[1] = true;

    bfs(1, graph, visited, cnt, que);

    sort(cnt.begin(), cnt.end(), greater<int>());
    for (auto i : cnt) {
        if (cnt[0] != i)
            break;
        answer++;
    }


    return answer;
}