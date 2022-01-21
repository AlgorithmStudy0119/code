#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sorting(vector<int> a, vector<int> b)
{
    return a[0] > b[0];
}

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int p_jobs = 0;

    sort(jobs.begin(), jobs.end(), sorting);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> todo;


    while(p_jobs < jobs.size())
    {
        while(time >= jobs[p_jobs][0])
        {
            todo.push({jobs[p_jobs][0], jobs[p_jobs][1]});
            p_jobs++;

            if(p_jobs == jobs.size())
                break;
        }
        if(!todo.empty())
        {
            pair<int, int> curr = todo.top();
            todo.pop();
            time += curr.second;
            answer += (time - curr.first);
        }
        else
        {
            time += 1;
        }
    }

    while(!todo.empty())
    {
        pair<int, int> curr = todo.top();
        todo.pop();
        time += curr.second;
        answer += (time - curr.first);
    }

    return (answer / jobs.size());
}
