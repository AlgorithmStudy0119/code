#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int ppl = 0;
	int city = 0;
	cin >> ppl;
	cin >> city;
	pair<int, int> cost;
	vector<pair<int, int>> vv;
	int dp[100001];

	int a;
	int b;
	// vv에 비용, 고객수 삽입
	for (int i = 0;i < city;i++) {
		cin >> a;
		cin >> b;
		vv.push_back(make_pair(a, b));
	}

	int tmp1 = 0;
	// dp[비용] 
	for (int i = 0;i < vv.size();i++) {
		for (int j = 1;j <= 100000;j++) {
			if (j - vv[i].first >= 0) {
				tmp1 = j - vv[i].first;
				dp[j] = max(dp[j], dp[tmp1] + vv[i].second);
			}
		}
	}

	for (int i = 1;i <= 100000;i++) {
		if (dp[i] >= ppl) {
			cout << i;
			break;
		}
	}
	return 0;
}
