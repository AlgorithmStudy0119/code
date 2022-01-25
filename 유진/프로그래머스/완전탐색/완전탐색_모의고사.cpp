#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int pl1 = 0;
    int pl2 = 0;
    int pl3 = 0;
    for (int i = 0;i < answers.size();i++) {
        if ((i % 5) + 1 == answers[i]) {
            pl1 += 1;
        }
        if (i % 2 == 0 && answers[i] == 2) {
            pl2 += 1;
        }
        if (i % 2 != 0) {
            if (i % 8 == 1 && answers[i] == 1)
                pl2 += 1;
            if (i % 8 == 3 && answers[i] == 3)
                pl2 += 1;
            if (i % 8 == 5 && answers[i] == 4)
                pl2 += 1;
            if (i % 8 == 7 && answers[i] == 5)
                pl2 += 1;
        }
        if (i % 10 == 0 || i % 10 == 1) {
            if (answers[i] == 3)
                pl3 += 1;
        }
        if (i % 10 == 2 || i % 10 == 3) {
            if (answers[i] == 1)
                pl3 += 1;
        }
        if (i % 10 == 4 || i % 10 == 5) {
            if (answers[i] == 2)
                pl3 += 1;
        }
        if (i % 10 == 6 || i % 10 == 7) {
            if (answers[i] == 4)
                pl3 += 1;
        }
        if (i % 10 == 8 || i % 10 == 9) {
            if (answers[i] == 5)
                pl3 += 1;
        }
    }

    int tmp = max({ pl1, pl2, pl3 });
    if (tmp == pl1) {
        answer.push_back(1);
    }
    if (tmp == pl2) {
        answer.push_back(2);
    }
    if (tmp == pl3) {
        answer.push_back(3);
    }

    return answer;
}