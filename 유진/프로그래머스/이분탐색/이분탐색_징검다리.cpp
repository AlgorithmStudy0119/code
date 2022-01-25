#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1;
    int end = distance;
    vector<int> length;
    sort(rocks.begin(), rocks.end());

    while (start <= end) {
        int mid = (start + end) / 2;
        int remove_cnt = 0; // 제거한 돌 개수
        int prev = 0; // 비교지점
        for (int i = 0;i < rocks.size();i++) {
            if (mid > rocks[i] - prev) { // 출발지점에서 바위까지 거리가 mid보다 작으면, 해당 바위 제거
                remove_cnt++;
            }
            else {
                prev = rocks[i]; // 비교시점에 현재 바위 위치로 초기화
            }
        }
        if (remove_cnt > n) {
            end = mid - 1; // 최대 거리 줄이기
        }
        else {
            start = mid + 1;
            answer = mid; // 최소 거리 줄이기
        }
    }
    return answer;
}