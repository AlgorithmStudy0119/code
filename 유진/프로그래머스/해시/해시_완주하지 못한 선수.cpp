#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mymap;
    // key : completion[i], value : ����
    for (auto c : completion) {
        mymap[c] += 1;
    }
    // key : participant[i], value : ����-1
    for (auto p : participant) {
        mymap[p] -= 1;
        if (mymap[p] < 0) { // key�� 0���� ���� ���, �������� ����
            printf("%s", p.c_str());
            answer = p;
        }
    }
    return answer;
}