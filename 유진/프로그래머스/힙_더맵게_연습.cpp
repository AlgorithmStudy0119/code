#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    vector<int> vec;
    sort(scoville.begin(), scoville.end());

    while (scoville[0] < K) {
        int tmp = 0;
        tmp = scoville[0] + (scoville[1] * 2);
        scoville.erase(scoville.begin() + 0, scoville.begin() + 2);
        scoville.push_back(tmp);
        sort(scoville.begin(), scoville.end());
        answer++;
    }


    return answer;
}