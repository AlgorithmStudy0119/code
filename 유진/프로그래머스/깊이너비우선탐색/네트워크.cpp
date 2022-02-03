#include <string>
#include <vector>

using namespace std;
vector<bool> visited(200, false);

void dfs(int n, vector<vector<int>>& computers, int index) {
    visited[index] = true;
    for (int i = 0;i < n;i++) {
        if (visited[i] == false && computers[index][i] == 1) {
            dfs(n, computers, i);
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0;i < n;i++) {
        if (visited[i] == false) {
            dfs(n, computers, i);
            answer++;
        }

    }
    return answer;
}
