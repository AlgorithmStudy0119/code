#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int helper(vector<int> array, vector<int> command)
{
    sort(array.begin() + command[0] - 1, array.begin() + command[1]);
    return array[command[0] + command[2] - 2];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int idx = 0; idx < commands.size(); idx++)
        answer.push_back(helper(array, commands[idx]));

    return answer;
}
