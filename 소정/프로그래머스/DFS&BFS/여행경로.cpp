#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visited[10001] = {false, };
vector<string> answer;
int max_count = 0;

void dfs(vector<vector<string>> tickets, vector<string> tmp, string start, int count)
{
    tmp.push_back(start);
    
    if(max_count < count)
    {
        max_count = count;
        answer = tmp;
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i][0] == start && visited[i] == false)
        {
            visited[i] = true;
            dfs(tickets, tmp, tickets[i][1], count + 1);
            visited[i] = false;
        }
    }
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> tmp;
    
    dfs(tickets, tmp, "ICN", 0);
    
    return answer;
}