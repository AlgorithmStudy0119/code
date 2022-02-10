#include <string>
#include <vector>
using namespace std;

void dfsearch(vector<int> &ans, vector<int> &lion, vector<int> &apch, int cnt, int left, int &diff)
{
  /* end check */
  if(left == 0 || cnt == 11)
  {
    int cur_diff = 0;
    lion[10] += left;

    /* diff calculation */
    for(int idx = 0; idx < 11; idx++)
    {
      if(lion[idx] == 0 && apch[idx] == 0)
        continue;
      cur_diff += (lion[idx] > apch[idx])? (10-idx) : (idx-10);
    }

    /* update diff + answer */
    if(cur_diff > diff)
    {
      diff = cur_diff;
      ans = lion;
    }

    if(cur_diff == diff)
    {
      bool flag = false;

      for(int idx = 0; idx < 11; idx++)
      {
        if(lion[10-idx] > ans[10-idx])
        {
          flag = true;
          break;
        }
        if(lion[10-idx] < ans[10-idx])
        {
          break;
        }
      }
      if(flag)
        ans = lion;
    }
    lion[10] -= left;
    return;
  }


  /* dfs search */
  if(apch[cnt] < left)
  {
    lion[cnt] = apch[cnt] + 1;
    dfsearch(ans, lion, apch, cnt+1, left-lion[cnt], diff);
    lion[cnt] = 0;
  }
  dfsearch(ans, lion, apch, cnt+1, left, diff);
  return;
}


vector<int> solution(int n, vector<int> info)
{
  int diff = 0;
  vector<int> lion(11,0);
  vector<int> ans(1, -1);
  dfsearch(ans, lion, info, 0, n, diff);

  return ans;
}
