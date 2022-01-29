#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    bool flag[people.size()];
    memset(flag, 0, sizeof(flag));

    int jdx = people.size()-1;

    for(int idx = 0; idx < people.size(); idx++)
    {
      if(flag[idx])
        continue;

      for(; jdx > idx; jdx--)
      {
        if(flag[jdx])
          continue;

        if(people[idx] + people[jdx] <= limit)
        {
          flag[idx] = true;
          flag[jdx] = true;
          break;
        }
      }

      if(!flag[idx])
        flag[idx] = true;

      answer++;
    }

    return answer;
}
