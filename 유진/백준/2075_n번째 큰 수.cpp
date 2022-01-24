#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a > b;
}

int main() {
	// cin, cout ÃÖÀûÈ­
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>,greater<int>> pque;
	
	for (int i = 0;i < n;i++) {
		int tmp = 0;
		cin >> tmp;
		pque.push(tmp);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int data = 0;
			cin >> data;
			pque.push(data);
		}
		for (int i = 0; i < n; i++)
			pque.pop();
	}
	cout << pque.top();

	return 0;
}