#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    // 이분탐색 : 최소값, 최대값을 절반으로 나눠 해당 값이 동일한지, 작은지, 큰지 판단
    long long start = 1;
    long long end = (long long)times[times.size() - 1] * n; // 최대시간 : 가장 킨 심사*n

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;

        for (int i = 0;i < times.size();i++) {
            cnt += mid / (long long)times[i]; // tmp 안에 심사할수있는 사람
        }

        // 총 사람보다 많은 사람을 심사할 수 있는 경우
        if (cnt >= n) {
            end = mid - 1; // 최대 시간 줄이기
            answer = mid;
            //cout << answer << " ";
        }
        else {
            start = mid + 1; // 최소시간 늘리기
        }
    }

    return answer;
}
