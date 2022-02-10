#include <string>
#include <vector>
#include <iostream>
using namespace std;

int diff;
vector<int> answer(1, -1);

bool better(vector<int>& lion) {
    for (int i = 10; i >= 0; i--) {
        if (lion[i] > answer[i])
            return true;
        else if (lion[i] < answer[i])
            return false;
    }
}

// ���� ���
void score(vector<int>& lion, vector<int>& apeach) {
    int lion_score = 0;
    int apeach_score = 0;
    for (int i = 0; i < 11; i++) {
        if (lion[i] > apeach[i])
            lion_score += 10 - i;
        else if (apeach[i] > 0)
            apeach_score += 10 - i;
    }

    int win = lion_score - apeach_score;
    if (win > 0 && win >= diff) {
        if (diff == win && !better(lion))
            return;

        diff = win;
        answer = lion;
    }
}

void greedy(int idx, int n, vector<int>& lion, vector<int>& apeach) {
    // ȭ�� ������ 0���� ����
    if (idx == 11 || n == 0) {
        lion[10] += n;
        score(lion, apeach);
        lion[10] -= n;
        return;
    }

    // 0~10 �� ���̾��� �̱� ���� -> ����ġ���� 1�� �� ��
    if (apeach[idx] < n) {
        lion[idx] += apeach[idx] + 1;
        greedy(idx + 1, n - apeach[idx] - 1, lion, apeach);
        lion[idx] -= apeach[idx] + 1;
    }

    // ���̾��� ���� ���� -> ���� ����
    greedy(idx + 1, n, lion, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);

    greedy(0, n, lion, info);

    return answer;
}
