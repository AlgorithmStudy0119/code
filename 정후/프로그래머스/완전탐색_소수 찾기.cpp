#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int answer = 0;
unordered_map<string, int> map;
unordered_map<int, int> map_answer;

bool sosu(int num, string str) {
	//if (str[0] == 48) return false;
	if (num < 2) return false;
	int a = (int)sqrt(num);for (int i = 2; i <= a; i++
	) if (num % i == 0) return false;
	if (map_answer.size() && map_answer.end() != map_answer.find(num)) return false;
	map_answer.insert({ num, 1 });
	return true;
}

void permutation(string str) {
	do {
		if (sosu(stoi(str), str)) answer++;
	} while (next_permutation(str.begin(), str.end()));
}

int solution(string numbers) {

	int len = numbers.size();

	sort(numbers.begin(), numbers.end());

	for (int i = 1; i <= len; i++) {
		vector<bool> v(len - i, false);
		v.insert(v.end(), i, true);
		do {
			string temp = "";
			for (int k = 0; k < len; k++) {
				if (v[k]) temp += numbers[k];
			}
			//if (map.size() && map.end() != map.find(temp)) continue;
			//map.insert({ temp, 1 });
			//cout << temp << endl;
			permutation(temp);
		} while (next_permutation(v.begin(), v.end()));
	}

	/*
	for (int i = 1; i <= len; i++) {
		vector<bool> v(len - i, false);
		v.insert(v.end(), i, true);
		do {
			string temp = "";
			for (int k = 0; k < len; k++) {
				if (v[k]) temp += numbers[k];
			}
			//if (map.size() && map.end() != map.find(temp)) continue;
			//map.insert({ temp, 1 });
			//cout << temp << endl;
			permutation(temp);
		} while (prev_permutation(v.begin(), v.end()));
	} */

	return answer;
}

int main() {
	string sss = "011";
	int a = solution(sss);

	//cout << a;

	return 0;
}
