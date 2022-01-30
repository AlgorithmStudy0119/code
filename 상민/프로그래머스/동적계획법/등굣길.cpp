#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int route[101][101];
    memset(route, 0, sizeof(route));

    for(int idx = 0; idx < puddles.size(); idx++)
        route[puddles[idx][0]][puddles[idx][1]] = -1;

    route[1][1] = 1;

    for(int sdx = 3; sdx <= m + n; sdx++)
    {
        for(int rdx = 1; rdx < sdx; rdx++)
        {
            if(sdx-rdx > 100 || rdx > 100)
                continue;

            if(route[rdx][sdx-rdx] == -1)
            {
                route[rdx][sdx-rdx] = 0;
                continue;
            }
            route[rdx][sdx-rdx] = (route[rdx-1][sdx-rdx] + route[rdx][sdx-rdx-1]) % 1000000007;
        }
    }


    return route[m][n];
}
