#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1;
    int end = distance;
    vector<int> length;
    sort(rocks.begin(), rocks.end());

    while (start <= end) {
        int mid = (start + end) / 2;
        int remove_cnt = 0; // ������ �� ����
        int prev = 0; // ������
        for (int i = 0;i < rocks.size();i++) {
            if (mid > rocks[i] - prev) { // ����������� �������� �Ÿ��� mid���� ������, �ش� ���� ����
                remove_cnt++;
            }
            else {
                prev = rocks[i]; // �񱳽����� ���� ���� ��ġ�� �ʱ�ȭ
            }
        }
        if (remove_cnt > n) {
            end = mid - 1; // �ִ� �Ÿ� ���̱�
        }
        else {
            start = mid + 1;
            answer = mid; // �ּ� �Ÿ� ���̱�
        }
    }
    return answer;
}