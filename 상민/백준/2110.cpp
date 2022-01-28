#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int N, C;

int device_cnt(ll *pos, ll interval)
{
  int cnt = 1;
  ll prev = pos[0];

  for(int idx = 1; idx < N; idx++)
  {
    if(pos[idx] - prev >= interval)
    {
      cnt++;
      prev = pos[idx];
    }
  }

  return cnt;
}

int main()
{
  cin >> N >> C;

  ll *pos = (ll*)malloc(sizeof(ll) * N);

  for(int idx = 0; idx < N; idx++)
    cin >> pos[idx];

  sort(pos, pos + N);

  ll result = 0;
  ll start = 0;
  ll end = pos[N-1] - pos[0];

  while(start != end)
  {
    ll mid = (start + end) / 2 + 1;
    int cnt = device_cnt(pos, mid);

    if(cnt >= C)
      start = mid;
    else
      end = mid-1;
  }

  cout << start;
}
