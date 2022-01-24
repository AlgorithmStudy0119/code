#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    int start = 1;
    int end = 1000000000;

    while(start != end)
    {
      int mid = (start + end) / 2 + 1;
      int prev = 0;
      int cnt = 0;

      for(int idx = 0; idx < rocks.size(); idx++)
      {
        int dist = rocks[idx] - prev;

        if(dist < mid)
          cnt++;
        else
          prev = rocks[idx];
      }

      if(distance - prev < mid)
        cnt++;

      if(cnt <= n)
        start = mid;
      else
        end = mid-1;
    }
    return start;
}
