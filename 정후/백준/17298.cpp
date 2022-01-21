#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> put, movemove, temp, answer;

void input();
void solve();

int main() {

	input();
	solve();

	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		put.push(a);
	}
}

void solve() {

	for (int i = 0; i < n; i++) {
		int value = put.top();
		put.pop();

		if (!movemove.size()) {		// 오큰수 없으면 
			answer.push(-1);
			movemove.push(value);
			continue;
		}

		while (!movemove.empty()) {
			int top = movemove.top();

			if (top > value) {
				answer.push(top);
				break;
			}
			else {
				movemove.pop();
				temp.push(top);
			}
		}

		while (!temp.empty()) {
			int top = temp.top();
			temp.pop();
			movemove.push(top);
		}

		movemove.push(value);

		if (put.size() == 0 && answer.size() != n) {
			answer.push(-1);
		}

	}

	for (int i = 0; i < n; i++) {
		cout << answer.top() << " ";
		answer.pop();
	}

}
