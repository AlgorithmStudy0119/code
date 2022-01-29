#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    queue<int> bfs;

    bfs.push(-numbers[0]);
    bfs.push(numbers[0]);

    int cnt = 2;

    for(int idx = 1; idx < numbers.length(); idx++)
    {
      for(int cdx = 0; cdx < cnt; cdx++)
      {
        int curr = bfs.front();
        bfs.pop();

        bfs.push(curr + numbers[idx]);
        bfs.push(curr - numbers[idx]);
      }
      cnt *= 2;
    }

    while(!bfs.empty())
    {
      int curr = bfs.front();
      bfs.pop();
      if(curr == target)
        answer++;
    }

    return answer;
}
