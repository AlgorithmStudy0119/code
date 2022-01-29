#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), compare);
    int cam = -99999;

    for(int rdx = 0; rdx < routes.size(); rdx++)
    {
        if(routes[rdx][0] > cam)
        {
            cam = routes[rdx][1];
            answer++;
        }
    }
    return answer;
}
