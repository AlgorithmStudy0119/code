#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <iostream>
using namespace std;

/* dir: left-false / right-true */
int helper(string input, bool dir, int iter)
{
  int a_cnt = 0;
  int len = input.length();
  for(int idx = 0; idx < len; idx++)
  {
    if(input[idx] != 'A')
      a_cnt++;
  }

  int result = 0;
  int i_cnt = 0;

  while(i_cnt < a_cnt)
  {
    if(input[iter] != 'A')
      i_cnt++;

    iter = dir? (iter + 1) : (iter - 1 + len) % len;
    result++;
  }
  return result == 0? result : result-1;
}

int solution(string name)
{
  int answer = 0;
  int len = name.length();

  for(int idx = 0; idx < len; idx++)
    answer += min(name[idx] - 'A', 'Z' - name[idx] + 1);

  int route = len;

  for(int idx = 1; idx < len; idx++)
  {
    int a = helper(name.substr(0, idx), true, 0) * 2 + helper(name.substr(idx, len-idx), false, len-idx-1) + 1;
    int b = helper(name.substr(idx, len-idx), false, len-idx-1) * 2 + 2 + helper(name.substr(0, idx), true, 0);

    route = min(min(a, b), route);
  }

  route = min(route, min(helper(name, false, 0), helper(name, true, 0)));

  return answer + route;

}
