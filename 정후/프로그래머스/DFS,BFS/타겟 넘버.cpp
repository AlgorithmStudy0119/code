#include <string>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0, target_num = 0;
vector<int> num;
int arr[2] = { 1,-1 };

void dfs(int depth, int sum);

int solution(vector<int> numbers, int target) {

    target_num = target;
    for (int i = 0; i < numbers.size(); i++)
        num.push_back(numbers[i]);

    dfs(0, 0);

    return answer;
}

void dfs(int depth, int sum) {
    if (depth == num.size()) {
        if (sum == target_num)
            answer++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        dfs(depth + 1, sum + (num[depth] * arr[i]));
    }

}
