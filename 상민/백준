#include <iostream>
#include <memory.h>
#include <cmath>
#include <limits.h>
using namespace std;
typedef pair<int, int> cod;

int C, N;
cod city[20];
int dp[1001];


int main()
{
  /* input */
  cin >> C >> N;
  int cost, num;

  for(int ndx = 0; ndx < N; ndx++)
  {
    cin >> cost >> num;
    city[ndx] = {cost, num};
  }

  /* initialization */
  memset(dp, 0x3f, sizeof(dp));

  /* dynamic programming (knapsack) */
  for(int cdx = 0; cdx <= C; cdx++)
  {
    if(cdx <= 0)
    {
      dp[cdx] = 0;
      continue;
    }
    for(int idx = 0; idx <N; idx++)
    {
      if(city[idx].second <=  cdx)
      {
        dp[cdx] = min(dp[cdx], dp[cdx-city[idx].second] + city[idx].first);
      }
      else
      {
        dp[cdx] = min(dp[cdx], dp[0] + city[idx].first);
      }
    }
  }

  /* output */
  cout << dp[C];

}
