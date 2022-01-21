#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> s;
    int result[1000001];
    int seq[1000001];

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= seq[i])
			s.pop();

		if (s.empty()) result[i] = -1;
		else result[i] = s.top();

		s.push(seq[i]);
	}
	
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
}