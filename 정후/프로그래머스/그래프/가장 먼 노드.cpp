#include <string>
#include <vector>
#include <queue>

using namespace std;

int distance_node[20001];
int max_dis;
vector<int> node[50001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < node[current].size(); i++) {
            if (distance_node[node[current][i]] == 0 && node[current][i] != 1) {
                distance_node[node[current][i]] = distance_node[current] + 1;
                q.push(node[current][i]);
                max_dis = max(max_dis, distance_node[node[current][i]]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (max_dis == distance_node[i])
            answer++;
    }
    return answer;
}
