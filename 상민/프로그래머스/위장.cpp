#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

bool compare(vector<string> a, vector<string> b)
{
    return a[a.size()-1] > b[b.size()-1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int arr[clothes.size()];
    memset(arr, 0, sizeof(arr));

    sort(clothes.begin(), clothes.end(), compare);
    int ptr = 0;

    for(int idx = 0; idx < clothes.size(); idx++)
    {
        arr[ptr] += 1;

        if(idx == clothes.size()-1)
            continue;

        if(clothes[idx][1] != clothes[idx + 1][1])
            ptr++;
    }

    for(int idx = 0; idx <= ptr; idx++)
        answer *= (arr[idx] + 1);


    return answer -1;
}
