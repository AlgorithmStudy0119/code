#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), comp);
    int camera = -30001; //ī�޶� ��ġ�� ��ġ
    // ��������� ī�޶� ��ġ
    for (int i = 0;i < routes.size();i++) {
        if (camera < routes[i][0]) {
            camera = routes[i][1];
            answer++;
        }
    }

    return answer;
}