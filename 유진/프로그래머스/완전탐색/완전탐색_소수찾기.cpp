#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// max������ �ִ� �Ҽ����� ���Ѵ�.
// numbers ���� ���ڵ�� �� �Ҽ��� ����� �ִ°� ���Ѵ�.

int solution(string numbers) {
    int answer = 0;
    int max = 0;
    int d[9999999] = { 0, };
    vector<int> arr(10, 0);
    bool check[7]; // numbers ���� 1~7

    sort(numbers.begin(), numbers.end(), greater<>()); // greater : ��������
    max = stoi(numbers); //stoi : string->int

    // �����佺�׳׽��� ü : �Ҽ� ã�� ���
    for (int i = 2;i < max;i++) {
        if (d[i] == 1) continue;  // d[i] = 1�̸�, �Ҽ��� �ƴϹǷ� �Ʒ��ڵ��ʿ�X
        for (int j = i + i;j <= max;j += i) {  // 2�� ������ 2�� ��� 1�� ����, 3�� ������ 3�� ��� 1�� ����,...
            d[j] = 1;
        }
    }

    //numbers���� �� �ڸ��� ���� ������ �迭�� ����
    for (int i = 0;i < numbers.size();i++) {
        arr[numbers[i] - '0']++;
    }
    cout << "max : " << max << endl;

    for (int i = 2;i <= max;i++) {
        if (d[i] != 0) continue;  // �Ҽ��� �ƴ�
        string a = to_string(i); // a : �Ҽ�
        vector<int> nn = arr;  // nn : �� �ڸ� ���� ���� �迭
        for (int j = 0;j < a.size();j++) {
            // cout << "a[" << j <<"] : "<< a[j] << endl;
            if (nn[a[j] - '0'] == 0) break;
            nn[a[j] - '0']--;
            if (j == a.size() - 1)
                answer++;
        }
    }

    return answer;
}