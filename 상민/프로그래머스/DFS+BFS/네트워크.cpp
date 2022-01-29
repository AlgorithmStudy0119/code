#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    bool visit[n];
    memset(visit, 0, sizeof(visit));

    for(int cdx = 0; cdx < n; cdx++)
    {
      if(visit[cdx])
        continue;

      queue<int> bsearch;
      bsearch.push(cdx);
      visit[cdx] = true;

      while(!bsearch.empty())
      {
        int curr = bsearch.front();
        bsearch.pop();

        for(int idx = 0; idx < n; idx++)
        {
          if(computers[curr][idx] && !visit[idx])
          {
            bsearch.push(idx);
            visit[idx] = true;
          }
        }
      }
      answer++;
    }

    return answer;
}
