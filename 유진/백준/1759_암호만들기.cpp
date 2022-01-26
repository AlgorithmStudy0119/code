#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int L = 0; // 암호 길이
int C = 0; // 문자 개수
map<string, bool> visited;
vector<string> pass;
vector<string> vec1; // 모음
vector<string> vec2; // 자음
vector<string> ans;

// 모음 인덱스, 자음 인덱스, 모음 개수, 자음 개수, 정답문자열
void password(int a, int b, int cnt1, int cnt2, string str) {
	// 모음 1개 이상, 자음 2개 이상, 문자열 길이 L이면, 정답문자열에 삽입
	if (str.length() == L && cnt1 >= 1 && cnt2 >= 2) {
		sort(str.begin(), str.end());
		if (!visited.count(str)) { // 방문 확인
			visited[str] = true;
			ans.push_back(str);
		}
		return;
	}

	// 모음
	for (int i = a;i < vec1.size();i++) {
		password(i+1, b, cnt1+1, cnt2, str+vec1[i]); 

	}
	// 자음
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
		// 모음 벡터
		if (pass[i] == "a" || pass[i] == "e" || pass[i] == "i" || pass[i] == "o" || pass[i] == "u") {
			vec1.push_back(pass[i]);
		}
		// 자음 벡터
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