#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int sum = 1;
    map<string, int> clo;
    // key : 의상종류, value : 의장 종류의 개수
    for (int i = 0;i < clothes.size();i++) {
        clo[clothes[i][1]] += 1;
    }
    // 조합 수 : (의상 종류 개수 + 1)의 곱 -1
    for (auto i : clo)
    {
        sum = sum * (i.second + 1);
    }
    answer = sum - 1;

    return answer;
}