#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int index, vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            dfs(i, computers);
        }
    }

    return answer;
}

void dfs(int index, vector<vector<int>> computers) {
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i] && computers[index][i]) {
            visited[i] = true;
            dfs(i, computers);
        }
    }
}
