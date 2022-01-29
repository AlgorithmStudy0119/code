#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
  int answer = 0;

  int count[n];

  for(int idx = 0; idx < n; idx++)
    count[idx] = 1;

  for(int idx = 0; idx < lost.size(); idx++)
    count[lost[idx]-1]--;

  for(int idx = 0; idx < reserve.size(); idx++)
    count[reserve[idx]-1]++;

  for(int idx = n-1; idx >= 0; idx--)
  {
    if(count[idx] != 0)
      continue;

    bool flag = false;
    if(idx != n-1)
    {
      if(count[idx + 1] == 2)
      {
        count[idx+1]--;
        count[idx]++;
        flag = true;
      }
    }
    if(idx !=0 && !flag)
    {
      if(count[idx - 1] == 2)
      {
        count[idx-1]--;
        count[idx]++;
      }
    }
  }

  for(int idx = 0; idx < n; idx++)
  {
      if(count[idx] > 0)
          answer++;
  }

  return answer;
}
