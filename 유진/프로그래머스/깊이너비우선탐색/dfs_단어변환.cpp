#include <string>
#include <vector>

using namespace std;
vector<int> visited(100, false);
int answer = 50;

// 다른 문자가 한개인지 판별하는 함수
bool check_word(string a, string b) {
    int dif_cnt = 0;
    for (int i = 0;i < a.size();i++) {
        if (a[i] != b[i])
            dif_cnt++;
    }
    if (dif_cnt == 1) {
        return true;
    }
    return false;
}

void dfs(string begin, string target, vector<string>& words, int index) {
    // index이 이전에 찾은 answer보다 크면 탐색할 필요X
    if (index >= answer) return;
    if (target == begin) {
        answer = min(answer, index);
        return;
    }

    for (int i = 0;i < words.size();i++) {
        if (visited[i] == false && check_word(begin, words[i]) == true) {
            visited[i] = true;
            dfs(words[i], target, words, index + 1);
            visited[i] = false;  //백트래킹하여 다시 false한 후 다시 탐색
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if (answer == 50)
        return 0;
    return answer;
}