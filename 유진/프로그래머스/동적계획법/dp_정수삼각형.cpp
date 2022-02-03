#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size));
    dp[0][0] = triangle[0][0];

    for (int i = 1;i < size;i++) {
        for (int j = 0;j <= i;j++) {
            // 哭率 场
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            // 坷弗率 场
            if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }

        }
    }
    for (int i = 0;i < size;i++) {
        if (answer < dp[size - 1][i]) {
            answer = dp[size - 1][i];
        }
    }
    return answer;
}