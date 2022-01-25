#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// max값까지 있는 소수들을 구한다.
// numbers 안의 숫자들로 그 소수를 만들수 있는가 구한다.

int solution(string numbers) {
    int answer = 0;
    int max = 0;
    int d[9999999] = { 0, };
    vector<int> arr(10, 0);
    bool check[7]; // numbers 길이 1~7

    sort(numbers.begin(), numbers.end(), greater<>()); // greater : 내림차순
    max = stoi(numbers); //stoi : string->int

    // 에라토스테네스의 체 : 소수 찾는 방법
    for (int i = 2;i < max;i++) {
        if (d[i] == 1) continue;  // d[i] = 1이면, 소수가 아니므로 아래코드필요X
        for (int j = i + i;j <= max;j += i) {  // 2를 제외한 2의 배수 1로 변경, 3읠 제외한 3의 배수 1로 변경,...
            d[j] = 1;
        }
    }

    //numbers에서 각 자리의 숫자 개수를 배열에 저장
    for (int i = 0;i < numbers.size();i++) {
        arr[numbers[i] - '0']++;
    }
    cout << "max : " << max << endl;

    for (int i = 2;i <= max;i++) {
        if (d[i] != 0) continue;  // 소수가 아님
        string a = to_string(i); // a : 소수
        vector<int> nn = arr;  // nn : 각 자리 숫자 개수 배열
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