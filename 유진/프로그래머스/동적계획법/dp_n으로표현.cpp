#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> dp(8);
    string num = to_string(N);
    string tmp_num = num;

    for (int i = 0;i < 8;i++) {
        dp[i].insert(stoi(tmp_num));
        tmp_num += num;
    }

    if (N == number) {
        return 1;
    }

    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < i;j++) {
            for (auto& x : dp[j]) {
                for (auto& y : dp[i - j - 1]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x * y);
                    dp[i].insert(x - y);
                    if (y != 0) {
                        dp[i].insert(x / y);
                    }
                }
            }
        }
        if (dp[i].find(number) != dp[i].end()) {
            return i + 1;
        }
    }

    return -1;
}