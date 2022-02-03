#include <vector>
using namespace std;
 
bool dfs(vector<vector<int>>& computers, int n) {
    if (!computers[n][n])    return false;
    
    //순회했음 체크
    computers[n][n] = 0;
    for (int i = 0; i < computers.size(); i++) {
        //연결된 노드가 있다면
        if (computers[n][i]){
            dfs(computers, i);
        }
    }
    return true;
}
 
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (computers[i][i] && dfs(computers, i)){
            answer++;
        }
    }
    return answer;
}