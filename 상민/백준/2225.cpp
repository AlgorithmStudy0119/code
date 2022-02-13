#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;

ll rem = 1000000000;
int N, K;
ll dp[201][201];

int main()
{
  cin >> N >> K;

  memset(dp, 0, sizeof(dp));

  for(int kdx = 1; kdx <= K; kdx++)
  {
    for(int ndx = 0; ndx <= N; ndx++)
    {
      if(kdx == 1 || ndx == 0)
      {
        dp[kdx][ndx] = 1;
        continue;
      }
      for(int nndx = 0; nndx <= ndx; nndx++)
        dp[kdx][ndx] += (dp[kdx-1][nndx] % rem);
    }
  }

  cout << dp[K][N] % rem;
}
