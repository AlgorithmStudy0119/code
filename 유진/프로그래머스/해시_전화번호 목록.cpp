#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string tmp = "";
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0;i < phone_book.size() - 1;i++) {
        tmp = phone_book[i + 1].substr(0, phone_book[i].size());
        // 정렬후 phone_book[i]가 i+1의 접두어인지 확인
        if (phone_book[i] == tmp) {
            answer = false;
        }
    }

    return answer;
}