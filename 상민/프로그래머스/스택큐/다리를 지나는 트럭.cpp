#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <memory.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int ptr = 0;
    queue<int> bridge;
    int curr_w = 0;

    while(ptr != truck_weights.size())
    {
        if(bridge.size() == bridge_length)
        {
            curr_w -= bridge.front();
            bridge.pop();
        }

        if(curr_w + truck_weights[ptr] <= weight)
        {
            curr_w += truck_weights[ptr];
            bridge.push(truck_weights[ptr]);
            ptr++;
        }
        else
        {
            bridge.push(0);
        }
        answer++;
    }
    return answer + bridge_length;
}
