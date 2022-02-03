#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(string start, vector<vector<string>>& tickets, vector<string>& answer, vector<bool>& visited, int num) {
    answer.push_back(start);
    if (num == tickets.size()) {
        return true;
    }
    for (int i = 0;i < tickets.size();i++) {
        if (tickets[i][0] == start && visited[i] == false) {
            visited[i] = true;
            bool test = dfs(tickets[i][1], tickets, answer, visited, num + 1);
            if (test) return true;
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, answer, visited, 0);
    return answer;
}