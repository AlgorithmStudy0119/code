#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int all_box = brown + yellow;
    int root = sqrt(all_box);

    for (int i = 1; i <= root; i++) {
        if (!(all_box % i)) {       // 나누어 떨어지면
            v.push_back({ i,all_box / i });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int garo = v[i].first;
        int sero = v[i].second;

        if (((garo + sero - 2) == (brown / 2)) && (garo - 2) * (sero - 2) == yellow) {
            answer.push_back(sero);
            answer.push_back(garo);
            break;
        }

    }

    return answer;
}
