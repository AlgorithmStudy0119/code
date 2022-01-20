#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> stac;

    for (int i = 0; i < size;i++)
    {
        //스택이 비어있지않고, 스택 마지막 값이 현재값보다 크다면 -> 가격이 떨어졌다면
        while (!stac.empty() && prices[stac.top()] > prices[i])
        {
            //가격 떨어졌으므로, i-스택 마지막값 대입
            answer[stac.top()] = i - stac.top();
            //값 제거
            stac.pop();
            // 가격이 같은 값이 유지되었을 경우 현재 값보다 계속 작으므로 1개 차이씩 넣어줌
        }
        //가격이 떨어지지 않았다면, 현재 인덱스를 스택에 넣기
        stac.push(i);

    }
    // 스택이 빌때까지 반복
    while (!stac.empty())
    {
        //위에서 특정 위치에 이미 값을 넣었으므로 pushback이나 insert로 하면 X
        // 뒤에서부터 넣어야하므로 size-1에서 top값을 뺀다.
        answer[stac.top()] = size - stac.top() - 1;
        stac.pop();

    }
    return answer;
}