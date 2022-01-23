#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    // priority_queue<string, vector<string>,greater<string>> pque(operations.begin(),operations.end());
    string data;
    int value;
    vector<int> list;

    for (int i = 0;i < operations.size();i++) {
        // 숫자 삽입
        if (operations[i][0] == 'I') {
            data = operations[i].substr(operations[i].find('I') + 2); // 삽입할 숫자
            value = stoi(data);
            list.push_back(value);
            sort(list.begin(), list.end()); // 오름차순 정렬
        }
        // 최댓값 삭제
        else if (operations[i] == "D 1") {
            if (!list.empty()) {
                list.erase(list.begin() + (list.size() - 1));
            }
        }
        // 최소값 삭제
        else if (operations[i] == "D -1") {
            if (!list.empty()) {
                list.erase(list.begin());
            }
        }
    }


    if (!list.empty()) {
        // 최대값
        answer.push_back(list[list.size() - 1]);
        // 최소값
        answer.push_back(list[0]);
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }


    return answer;
}