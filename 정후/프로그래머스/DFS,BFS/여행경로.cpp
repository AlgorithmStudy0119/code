#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> temp;
vector<bool> visited;
vector<string> answer, real_answer;
int temp_num = 0;

bool comp(vector<string> s1, vector<string> s2) {
    return s1 < s2;
}

void dfs(string current, vector<vector<string>> tickets);

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end(), comp);

    for (int i = 0; i < tickets.size(); i++) {
        visited.push_back(false);
    }

    dfs("ICN", tickets);

    /*
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            answer.push_back(tickets[i][0]);
            visited[i] = true;
            dfs(tickets[i][1], tickets);
            break;
        }
    }*/

    return real_answer;
}


void dfs(string current, vector<vector<string>> tickets) {
    answer.push_back(current);

    if (answer.size() == tickets.size() + 1 && temp_num == 0) {
        temp_num = 1;
        real_answer = answer;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == current && !visited[i]) {
            visited[i] = true;
            dfs(tickets[i][1], tickets);
            visited[i] = false;
        }
        else if (i == tickets.size() - 1) {
            answer.pop_back();
        }
    }

}
