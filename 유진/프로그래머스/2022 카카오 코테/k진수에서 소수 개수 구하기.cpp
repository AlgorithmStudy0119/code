#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 소수 판별
bool prime(long long n) {
    if (n < 2)
        return false;
    for (int i = 2;i <= sqrt(n);i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = -1;

    //진법 바꾸기
    vector<int> tmp1;
    int res1 = n;
    while (res1 > 0) {
        tmp1.push_back(res1 % k);
        res1 = res1 / k;
    }

    // 소수 개수 구하기
    string prim = "";
    for (int i = tmp1.size() - 1;i >= 0;i--) {
        prim += to_string(tmp1[i]);
    }

    string tmp3 = "";
    int cnt = 0;
    for (int i = 0;i < prim.length();i++) {
        if (prim[i] == '0' && !tmp3.empty()) {
            long long n = stoll(tmp3);
            if (prime(n)) {
                cnt++;
            }
            tmp3 = "";
        }
        else {
            tmp3 += prim[i];
        }
    }
    if (!tmp3.empty()) {
        long long n = stoll(tmp3);
        if (prime(n)) {
            cnt++;
        }
    }
    answer = cnt;

    return answer;
}
