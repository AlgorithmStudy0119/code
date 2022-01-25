#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> no1;
vector<int> no2;
vector<int> no3;

int score_1 = 0, score_2 = 0, score_3 = 0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    while (no1.size() < 10000) {
        no1.push_back(1);
        no1.push_back(2);
        no1.push_back(3);
        no1.push_back(4);
        no1.push_back(5);
    }

    while (no2.size() < 10000) {
        no2.push_back(2);
        no2.push_back(1);
        no2.push_back(2);
        no2.push_back(3);
        no2.push_back(2);
        no2.push_back(4);
        no2.push_back(2);
        no2.push_back(5);
    }

    while (no3.size() < 10000) {
        no3.push_back(3);
        no3.push_back(3);
        no3.push_back(1);
        no3.push_back(1);
        no3.push_back(2);
        no3.push_back(2);
        no3.push_back(4);
        no3.push_back(4);
        no3.push_back(5);
        no3.push_back(5);
    }

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == no1[i]) score_1++;
        if (answers[i] == no2[i]) score_2++;
        if (answers[i] == no3[i]) score_3++;
    }

    int max = 0;
    if (score_1 > max) max = score_1;
    if (score_2 > max) max = score_2;
    if (score_3 > max) max = score_3;

    if (score_1 == max) answer.push_back(1);
    if (score_2 == max) answer.push_back(2);
    if (score_3 == max) answer.push_back(3);

    return answer;
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(4);
    a.push_back(2);

    vector<int> b = solution(a);

    return 0;
}
