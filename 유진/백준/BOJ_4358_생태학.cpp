#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	// key : 이름, value : 나온횟수
	map<string, int> tree_list;
	// 나무 전체 개수
	int cnt = 0;
	string n;

	// 공백문자 입력
	while (getline(cin, n)) {
		tree_list[n] += 1;
		cnt += 1;
	}

	cout.precision(4);
	cout << fixed;
	for (auto i : tree_list) {
		double tmp = i.second;
		double answer = tmp / cnt * 100;
		cout << i.first << " " << answer << "\n";
	}

	return 0;
}