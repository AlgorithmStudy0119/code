#include <string>
#include <queue>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    int visit[n+1];
    queue<int> search;

    for(int ndx = 1; ndx <= n; ndx++)
    {
      memset(visit, 0, sizeof(visit));
      visit[ndx] = 1;
      search.push(ndx);

      while(!search.empty())
      {
        int curr = search.front();
        search.pop();

        for(int idx = 0; idx < results.size(); idx++)
        {
          if(curr == results[idx][0] && visit[results[idx][1]] == 0)
          {
            visit[results[idx][1]] = 1;
            search.push(results[idx][1]);
          }
        }
      }

      search.push(ndx);

      while(!search.empty())
      {
        int curr = search.front();
        search.pop();

        for(int idx = 0; idx < results.size(); idx++)
        {
          if(curr == results[idx][1] && visit[results[idx][0]] == 0)
          {
            visit[results[idx][0]] = 1;
            search.push(results[idx][0]);
          }
        }
      }
      int cnt = 0;
      for(int idx = 0; idx <= n; idx++)
      {

        cnt += visit[idx];
      }

      if(cnt == n)
        answer++;
    }

    return answer;
}
