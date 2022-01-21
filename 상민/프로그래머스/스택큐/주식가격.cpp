#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int idx = 0; idx < prices.size(); idx++)
    {
        int cnt = 0;
        for(int jdx = idx; jdx < prices.size()-1; jdx++)
        {
            if(prices[idx] > prices[jdx])
                break;

            cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
