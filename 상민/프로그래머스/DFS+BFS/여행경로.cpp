#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

bool dfsearch(vector<vector<string>> tickets, vector<string> &answer, bool visit[])
{
  if(answer.size() == tickets.size() + 1)
    return true;

  string curr = answer.back();
  for(int tdx = 0; tdx < tickets.size(); tdx++)
  {
    if(curr == tickets[tdx][0] && !visit[tdx])
    {
      visit[tdx] = true;
      answer.push_back(tickets[tdx][1]);
      if(dfsearch(tickets, answer, visit))
        return true;
      answer.pop_back();
      visit[tdx] = false;
    }
  }
  return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    bool visit[tickets.size()];
    memset(visit, 0, sizeof(visit));

    answer.push_back("ICN");
    sort(tickets.begin(), tickets.end());

    dfsearch(tickets, answer, visit);

    return answer;
}
