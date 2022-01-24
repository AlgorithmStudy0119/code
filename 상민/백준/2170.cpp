#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> cod;



int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<int, int>> lines;

  int src, dst;

  for(int idx = 0; idx < N; idx++)
  {
    cin >> src >> dst;
    lines.push_back({src, dst});
  }

  sort(lines.begin(), lines.end());

  int len = lines[0].second - lines[0].first;
  int curr = lines[0].second;

  for(int idx = 1; idx < lines.size(); idx++)
  {
    if(curr > lines[idx].second)
    {
      continue;
    }
    if(curr > lines[idx].first)
    {
      len += (lines[idx].second - curr);
      curr  = lines[idx].second;
    }
    else
    {
      len += (lines[idx].second - lines[idx].first);
      curr = lines[idx].second;
    }
  }

  cout << len;
}
