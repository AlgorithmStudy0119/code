#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int num : numbers){
        v.push_back(to_string(num));
    }
    sort(v.begin(), v.end(), cmp);
    if(v[0]=="0")   return "0";
    
    for(string s : v){
        answer += s;
    }
    
    return answer;
}