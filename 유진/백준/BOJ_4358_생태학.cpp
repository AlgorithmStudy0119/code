#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	// key : �̸�, value : ����Ƚ��
	map<string, int> tree_list;
	// ���� ��ü ����
	int cnt = 0;
	string n;

	// ���鹮�� �Է�
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