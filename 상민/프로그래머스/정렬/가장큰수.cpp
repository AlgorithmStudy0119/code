#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> lst;

    for(auto el : numbers)
        lst.push_back(to_string(el));

    sort(lst.begin(), lst.end(), compare);

    if(lst[0] == "0")
            return "0";

    for(auto el = lst.begin(); el != lst.end(); el++)
        answer.append(*el);

    return answer;
}
