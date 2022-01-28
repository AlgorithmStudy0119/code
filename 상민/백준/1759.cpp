#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int L, C;
set<char> check = {'a', 'e', 'i', 'o' ,'u'};
set<string> result;
set<char> comb;

set<char> uselist;


void dfs_push(char curr[], int cnt, auto ptr)
{
  if(cnt == L)
  {
    int check_b = 0;
    for(int idx = 0; idx < L; idx++)
    {
      if(check.find(curr[idx]) == check.end())
        check_b++;
    }

    if(check_b < 2)
      return;

    char cur[L + 1];
    memcpy(cur, curr, sizeof(char) * L);
    sort(cur, cur + L);

    string str(cur, cur + L);

    if(result.find(str) == result.end())
      result.insert(str);

    return;
  }

  for(auto iter = ptr; iter != comb.end(); iter++)
  {
    if(uselist.find(*iter) == uselist.end())
    {
      uselist.insert(*iter);
      curr[cnt] = *iter;
      dfs_push(curr, cnt+1, next(iter, 1));
      uselist.erase(*iter);
    }
  }
}


int main()
{
  cin >> L >> C;

  vector<char> a;

  for(int idx = 0; idx < C; idx++)
  {
    char input;
    cin >> input;

    if(check.find(input) != check.end())
      a.push_back(input);

    comb.insert(input);
  }

  for(int idx = 0; idx < a.size(); idx++)
  {
    comb.erase(a[idx]);

    char curr[L + 1];
    curr[0] = a[idx];

    dfs_push(curr, 1, comb.begin());
  }


  for(auto iter = result.begin(); iter != result.end(); iter++)
    cout << (*iter) << '\n';

}
