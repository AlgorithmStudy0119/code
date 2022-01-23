#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;  // ���ڸ����� ���ڸ��� �񱳽�, ������ �� �� Ŀ���� ���� ����
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), greater<>());

    vector<string> tmp;
    for (int i = 0;i < numbers.size();i++) {
        tmp.push_back(to_string(numbers[i]));
    }

    sort(tmp.begin(), tmp.end(), compare);

    for (int i = 0;i < tmp.size();i++) {
        answer += tmp[i];
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}