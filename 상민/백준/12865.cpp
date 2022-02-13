#include <iostream>
#include <memory.h>
using namespace std;
typedef pair<int, int> el;          /* weight, value */

el lst[100];
int dp[101][100001];

int N, K;

int main()
{
  cin >> N >> K;
  int w, v;

  for(int ndx = 1; ndx <= N; ndx++)
  {
    cin >> w >> v;
    lst[ndx] = {w, v};
  }

  memset(dp, 0, sizeof(dp));

  for(int ndx = 1; ndx <= N; ndx++)
  {
    for(int wdx = 1; wdx <= K; wdx++)
    {
      if(wdx >= lst[ndx].first)
        dp[ndx][wdx] = max(dp[ndx-1][wdx], dp[ndx-1][wdx - lst[ndx].first] + lst[ndx].second);
      else
        dp[ndx][wdx] = dp[ndx-1][wdx];
    }
  }

  cout << dp[N][K];
}
