#include <vector>
#include <queue>
#include <memory.h>
#include <cmath>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist[n+1];
    bool visit[n+1]
    memset(dist, 0, sizeof(dist));
    memset(visit, 0, sizeof(visit));

    int max_dist = 0;
    queue<int> search;
    search.push(1);
    visit[1] = true;

    while(!search.empty())
    {
        int curr = search.front();
        search.pop();

        for(int iter = 0; iter < edge.size(); iter++)
        {
            if(edge[iter][0] == curr && !visit[edge[iter][1]])
            {
                visit[edge[iter][1]] = true;
                search.push(edge[iter][1]);
                dist[edge[iter][1]] = dist[curr] + 1;
                max_dist = max(max_dist, dist[curr] + 1);
            }
            if(edge[iter][1] == curr && !visit[edge[iter][0]])
            {
                visit[edge[iter][0]] = true;
                search.push(edge[iter][0]);
                dist[edge[iter][0]] = dist[curr] + 1;
                max_dist = max(max_dist, dist[curr] + 1);
            }
        }
    }

    for(int idx = 0; idx < n + 1; idx++)
    {
        if(max_dist == dist[idx])
            answer++;
    }

    return answer;
}
