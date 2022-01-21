#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
    int insert_cnt = 0;

    for(auto el : operations)
    {
        if(el[0] == 'I')
        {
            minheap.push(stoi(el.substr(2)));
            maxheap.push(stoi(el.substr(2)));
            insert_cnt++;
        }
        else if(el[2] == '-')
        {
            if(insert_cnt > 0)
            {
                minheap.pop();
                insert_cnt--;
            }
        }
        else
        {
            if(insert_cnt > 0)
            {
                maxheap.pop();
                insert_cnt--;
            }
        }

        if(insert_cnt == 0)
        {
            while(!maxheap.empty())
                maxheap.pop();
            while(!minheap.empty())
                minheap.pop();
        }
    }

    if(insert_cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxheap.top());
        answer.push_back(minheap.top());
    }

    return answer;
}
