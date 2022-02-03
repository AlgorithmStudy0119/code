#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;

    for (int i = 0;i < number.size() - k;i++) {
        char max = 0;
        for (int j = idx;j <= i + k;j++) {
            if (max < number[j]) {
                max = number[j];
                idx = j + 1;
            }
        }
        answer += max;
    }

    return answer;
}