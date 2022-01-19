#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for(int idx = 0; idx < phone_book.size()-1; idx++)
    {
        string curr = phone_book[idx];
        string next = phone_book[idx+1].substr(0, curr.size());

        if(next == curr)
                return !answer;
    }

    return answer;
}
