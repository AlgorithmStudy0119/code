#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int idx = 0; idx < participant.size(); idx++)
    {
        if(participant[idx] != completion[idx])
            return participant[idx];
    }
}
