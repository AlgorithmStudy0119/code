#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    answer = {0,0,0};
    vector<vector<int>> person = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    
    
    for(int idx = 0; idx < answers.size(); idx++)
    {
        for(int jdx = 0; jdx < 3; jdx++)
        {
            answer[jdx] += (person[jdx][idx % person[jdx].size()] == answers[idx]);
        }
    }
    
    int max = answer[0];
    
    for(int idx = 1; idx < 3; idx++)
    {
        if(max < answer[idx])
            max = answer[idx];
    }
    
    vector<int> result;
    
    for(int idx = 0; idx < 3; idx++)
    {
        if(max == answer[idx])
            result.push_back(idx+1);
    }
    
    return result;
}
