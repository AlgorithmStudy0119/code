#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    // vector<int> dp1;
    // vector<int> dp2;
    int dp1[1000000];
    int dp2[1000000];
    int num = money.size();
    dp1[0] = money[0];
    dp1[1] = dp1[0];
    dp2[0] = 0;
    dp2[1] = money[1];

    // x집 터는 경우 : dp[x] = dp[x-2] + money[x]
    // x집 안터는 경우 : dp[x] = dp[x-1]

    // 첫번째 집부터 훔치는 경우
    for (int i = 2;i <= num;i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    // 두번째 집부터 훔치는 경우
    for (int i = 2;i <= num;i++) {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }
    answer = max(dp1[num - 2], dp2[num - 1]);
    return answer;
}
