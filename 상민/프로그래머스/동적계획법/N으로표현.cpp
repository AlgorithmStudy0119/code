#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
typedef pair<int, int> el;

int solution(int N, int number) {
    int answer = 0;

    set<int> expr[9];

    int init = N;
    for(int idx = 1; idx < 9; idx++)
    {
        expr[idx].insert(init);
        init = init * 10 + N;
    }

    for(int idx = 1; idx < 9; idx++)
    {
        for(int jdx = 1; jdx < idx; jdx++)
        {
            for(auto iter = expr[jdx].begin(); iter != expr[jdx].end(); iter++)
            {
                for(auto jter = expr[idx-jdx].begin(); jter != expr[idx-jdx].end(); jter++)
                {
                    int a = *iter;
                    int b = *jter;
                    expr[idx].insert(a + b);
                    expr[idx].insert(a - b);
                    if(b != 0)
                        expr[idx].insert(a / b);
                    expr[idx].insert(a * b);
                }
            }
        }

        if(expr[idx].find(number) != expr[idx].end())
            return idx;
    }

    return -1;
}
