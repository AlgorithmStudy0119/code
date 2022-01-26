#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_answer = 1000000000;

    long long min = 0, max = 0;
    sort(times.begin(), times.end());

    min = (long long) times[0];                         // min = 1명이 제일 빠른 심사관에게 심사받는 경우
    max = (long long) times[times.size() - 1] * n;      // max = n명이 제일 느린 심사관에게 심사받는 경우

    while (min <= max) {
        long long mid = (min + max) / 2;
        long long count = 0;

        for (int i = 0; i < times.size(); i++)
            count += mid / times[i];        // mid 시간동안 모든 심사관이 감당할 수 있는 인원 수

        if (count < n) {
            min = mid + 1;
        }
        else {
            if (mid <= max)
                answer = mid;

            max = mid - 1;
        }
    }


    return answer;
}
