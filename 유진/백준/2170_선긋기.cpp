#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    vector<pair<int, int>> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    int start = arr[0].first; // �ʱⰪ
    int end = arr[0].second;
    for (int i = 1; i < n; i++) {
        int s_tmp = arr[i].first;
        int e_tmp = arr[i].second;
        if (end >= s_tmp) {
            if (end < e_tmp) {
                end = e_tmp;
            }
        }
        else {
            answer += end - start;
            start = s_tmp, end = e_tmp;
        }
    }
    answer += end - start;
    cout << answer;

    return 0;
}


