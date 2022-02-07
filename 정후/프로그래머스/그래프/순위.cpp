#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 0; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = true;
    }


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {   // i가 k 이기고, k가 j 이기면
                    graph[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                count++;
            }
        }

        if (count == n - 1) {   // 모든 결과 다 가지고 있으면 답 ++
            answer++;
        }
    }

    return answer;
}
