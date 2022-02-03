#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    set<int> dp[9];
    int tmp = 0;
    for(int i= 1; i<= 8; i++){ 
       tmp = tmp*10 + N;
        dp[i].insert(tmp);
    }

    for(int i = 1;i<= 8; i++) {
        for(int j = 1;j<=i; j++) {
            for( auto x : dp[j]) {
                for (auto y : dp[i-j]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    if( x!= 0 && y != 0) {
                     dp[i].insert(x * y);
                     dp[i].insert(x / y);
                    }
                }
            }
        }
        if(dp[i].find(number) != dp[i].end() ) return i;
    }
    return -1;
}
