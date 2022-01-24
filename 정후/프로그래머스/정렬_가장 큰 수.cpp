#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;

    for(auto number : numbers)
        str_numbers.push_back(to_string(number));     

    sort(str_numbers.begin(),str_numbers.end(),compare);

    if(str_numbers[0] == "0")
        return "0";

    for(auto number : str_numbers)
        answer += number;

    return answer;
}
