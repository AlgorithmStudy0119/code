#include <string>
#include <vector>

using namespace std;

long long lim = 1000000000;

/*
long long bsearch(long long start, long long end, int n, vector<int> times)
{
    if(start == end)
      return start;

    long long mid = (start + end) / 2;
    long long cnt = 0;

    for(int idx = 0; idx < times.size(); idx++)
      cnt += mid / times[idx];

    if(cnt >= mid)
      return bsearch(start, mid, n, times);
    else
      return bsearch(mid+1, end, n, times);
}
*/

long long bsearch(long long start, long long end, int n, vector<int> times)
{
  while(start != end)
  {
    long long mid = (start + end) / 2;
    long long cnt = 0;

    for(int idx = 0; idx < times.size(); idx++)
      cnt += mid / times[idx];

    if(cnt >= n)
      end = mid;
    else
      start = mid+1;
  }
  return start;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;

    return bsearch(1, lim * lim, n, times);

}
