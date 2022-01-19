#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int prior[10];
    memset(prior, 0, sizeof(prior));
    queue<pair<int, int>> print; // idx + priority

    for(int idx = 0; idx < priorities.size(); idx++)
    {
        prior[priorities[idx]] += 1;
        print.push({idx, priorities[idx]});
    }

    int cnt = 1;

    while(true)
    {
        int max_p;

        for(int idx = 9; idx > 0; idx--)
        {
            if(prior[idx] != 0)
            {
              max_p = idx;
              break;
            }
        }

        pair<int, int> curr = print.front();
        print.pop();

        if(max_p == curr.second)
        {
            prior[max_p]--;
            if(curr.first == location)
                return cnt;
            cnt++;
        }

        print.push(curr);
    }
}
