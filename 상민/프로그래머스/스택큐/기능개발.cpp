#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    stack<int> funclist;

    for(int idx = progresses.size()-1 ; idx >= 0; idx--)
        funclist.push((99 - progresses[idx] + speeds[idx]) / speeds[idx]);

    while(!funclist.empty())
    {
        int cnt = 1;
        int popped = funclist.top();
        funclist.pop();

        while(!funclist.empty())
        {
            if(funclist.top() <= popped)
            {
                funclist.pop();
                cnt+=1;
            }
            else
                break;
        }
        answer.push_back(cnt);
    }

    return answer;
}
