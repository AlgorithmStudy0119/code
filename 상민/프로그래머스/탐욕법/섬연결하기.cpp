#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

bool connect(int src, int dst, vector<vector<int>> bridge)
{
    queue<int> search;
    search.push(src);
    bool visit[bridge.size()];
    memset(visit, 0, sizeof(visit));

    while(!search.empty())
    {
        int curr = search.front();
        search.pop();

        if(curr == dst)
            return true;

        for(int idx = 0; idx < bridge.size(); idx++)
        {
            if(curr == bridge[idx][0] && !visit[idx])
            {
                visit[idx] = true;
                search.push(bridge[idx][1]);
            }
            if(curr == bridge[idx][1] && !visit[idx])
            {
                visit[idx] = true;
                search.push(bridge[idx][0]);
            }
        }
    }

    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> bridge;

    sort(costs.begin(), costs.end(), compare);

    for(int idx = 0; idx < costs.size(); idx++)
    {
        if(!connect(costs[idx][0], costs[idx][1], bridge))
            bridge.push_back(costs[idx]);
    }

    for(int idx = 0; idx < bridge.size(); idx++)
        answer += bridge[idx][2];

    return answer;
}
