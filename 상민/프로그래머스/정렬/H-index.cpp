#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    citations.push_back(0);
    sort(citations.begin(), citations.end(), less<int>());

    int idx = 0;

    for(; idx < citations.size(); idx++)
    {
        if(citations.size()-idx >= citations[idx])
            answer = citations[idx];
        else
            break;
    }

    for(int ptr = citations[idx]-1; ptr > answer; ptr--)
    {
        if(citations.size() - idx >=  ptr)
            return ptr;
    }

    return answer;
}
