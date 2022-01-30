#include <string>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int len = money.size();

    int acase[len];
    int bcase[len];
    memset(acase, 0, sizeof(acase));
    acase[0] = money[0];
    acase[1] = money[0];
    memset(bcase, 0, sizeof(bcase));
    bcase[1] = money[1];

    for(int idx = 2; idx < len; idx++)
    {
        acase[idx] = max(acase[idx-2] + money[idx], acase[idx-1]);
        bcase[idx] = max(bcase[idx-2] + money[idx], bcase[idx-1]);
    }

    return max(acase[len-2], bcase[len-1]);
}
