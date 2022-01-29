#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<string, int> el;

bool count(string curr, string word)
{
    int cnt = 0;
    for(int idx = 0; idx < curr.length(); idx++)
    {
        if(curr[idx] != word[idx])
            cnt++;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visit[words.size()];
    memset(visit, 0, sizeof(visit));

    queue<el> search;
    search.push({begin, 0});


    while(!search.empty())
    {
        el curr = search.front();
        search.pop();

        if(curr.first == target)
            return curr.second;

        for(int ptr = 0; ptr < words.size(); ptr++)
        {
            if(visit[ptr])
                continue;

            if(count(words[ptr], curr.first))
            {
                search.push({words[ptr], curr.second + 1});
                visit[ptr] = true;
            }
        }
    }
    return answer;
}
