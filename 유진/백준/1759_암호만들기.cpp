#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int L = 0; // ��ȣ ����
int C = 0; // ���� ����
map<string, bool> visited;
vector<string> pass;
vector<string> vec1; // ����
vector<string> vec2; // ����
vector<string> ans;

// ���� �ε���, ���� �ε���, ���� ����, ���� ����, ���乮�ڿ�
void password(int a, int b, int cnt1, int cnt2, string str) {
	// ���� 1�� �̻�, ���� 2�� �̻�, ���ڿ� ���� L�̸�, ���乮�ڿ��� ����
	if (str.length() == L && cnt1 >= 1 && cnt2 >= 2) {
		sort(str.begin(), str.end());
		if (!visited.count(str)) { // �湮 Ȯ��
			visited[str] = true;
			ans.push_back(str);
		}
		return;
	}

	// ����
	for (int i = a;i < vec1.size();i++) {
		password(i+1, b, cnt1+1, cnt2, str+vec1[i]); 

	}
	// ����
	for (int i = b;i < vec2.size();i++) {
		password(a, i+1, cnt1, cnt2+1, str+vec2[i]);
	}
}

int main()
{
	cin >> L >> C;

	string tmp = "";
	for (int i = 0;i < C;i++) {
		cin >> tmp;
		pass.push_back(tmp);
	}
	//sort(pass.begin(), pass.end());

	for (int i = 0;i < C;i++) {
		// ���� ����
		if (pass[i] == "a" || pass[i] == "e" || pass[i] == "i" || pass[i] == "o" || pass[i] == "u") {
			vec1.push_back(pass[i]);
		}
		// ���� ����
		else {
			vec2.push_back(pass[i]);
		}
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	password(0, 0, 0, 0, ""); // dfs

	sort(ans.begin(), ans.end());
	for (int i = 0;i < ans.size();i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}