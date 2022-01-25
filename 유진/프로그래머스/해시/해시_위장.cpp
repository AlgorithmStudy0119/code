#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int sum = 1;
    map<string, int> clo;
    // key : �ǻ�����, value : ���� ������ ����
    for (int i = 0;i < clothes.size();i++) {
        clo[clothes[i][1]] += 1;
    }
    // ���� �� : (�ǻ� ���� ���� + 1)�� �� -1
    for (auto i : clo)
    {
        sum = sum * (i.second + 1);
    }
    answer = sum - 1;

    return answer;
}