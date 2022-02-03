#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int idx = 0; // 가벼운사람 순으로 인덱싱
    int weight = 0;  // 가장 무거운 사람 몸무게 저장 변수

    sort(people.begin(), people.end());

    while (idx < people.size())
    {
        int weight = people.back(); // 가장 무거운 사람 몸무게 저장
        people.pop_back(); // 가장 무거운 사람 삭제
        // 구명보트에 최대 2명만 탈 수 있음
        // 가장 가벼운사람 + 가장 무거운사람 <= limit    -> 2명 탑승
        if (people[idx] + weight <= limit) {
            answer += 1;
            idx += 1;    // idx를 1 옮겨서, 2명이 한 구명보트에 타도록 카운팅        
        }
        // 가장 가벼운사람 + 가장 무거운사람 > limit     -> 1명만 탑승
        else {
            answer += 1;
        }
    }
    return answer;
}
