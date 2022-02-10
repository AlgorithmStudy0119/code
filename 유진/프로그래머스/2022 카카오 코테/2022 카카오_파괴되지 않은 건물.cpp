#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    int map[1010][1010];  // ����?

    // ������ �� �迭 ����
    for (auto i : skill) {
        int score = i[5];
        if (i[0] == 1) {
            score = -score;
        }
        map[i[1]][i[2]] += score;
        map[i[1]][i[4] + 1] -= score;
        map[i[3] + 1][i[2]] -= score;
        map[i[3] + 1][i[4] + 1] += score;
    }

    //��->�� ������
    for (int i = 0;i < n + 1;i++) {
        for (int j = 0;j < m;j++) {
            map[i][j + 1] += map[i][j];
        }
    }

    //��->�Ʒ� ������
    for (int i = 0;i < m + 1;i++) {
        for (int j = 0;j < n;j++) {
            map[i + 1][j] += map[i][j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (board[i][j] + map[i][j] > 0)
                answer++;
        }

    }
    return answer;
}