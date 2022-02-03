#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    string arr = "";
    int num = name.size();
    for (int i = 0;i < num;i++) {
        arr += "A";
    }

    int idx = 0;
    while (arr != name) {
        // ���� ��ġ ����
        answer += min(name[idx] - 'A', ('Z' + 1) - name[idx]);
        name[idx] = 'A';

        //���������� �̵�����, �������� �̵����� ���ϱ�
        for (int i = 1;i <= num / 2;i++) {
            int left = idx - i;
            int right = idx + i;
            if (left < 0) {
                left += num;
            }
            if (right >= num) {
                right -= num;
            }

            if (name[left] != 'A') {
                idx = left;
                answer += i;
                break;
            }
            else if (name[right] != 'A') {
                idx = right;
                answer += i;
                break;
            }
        }
    }

    return answer;
}