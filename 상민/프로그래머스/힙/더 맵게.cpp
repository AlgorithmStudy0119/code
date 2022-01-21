#include <string>
#include <vector>
#include <queue>

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, compare> food;
    
    for(auto el : scoville)
        food.push(el);
    
    while(food.top() < K)
    {
        if(food.size() == 1)
            return -1;
        
        int curr = food.top();
        food.pop();
        int next = food.top();
        food.pop();
        food.push(curr + next * 2);
        answer += 1;
    }

    return answer;
}
