#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = 0;
    sum = brown + yellow;
    int a,b;
    for(int i=1;i<=sum;i++){
        a = i; // 세로
        b = sum / a; // 가로
    
        if(a > b) // 세로가 더 길면 안된다.
            continue;

        if((a-2)*(b-2) == yellow){
            answer.push_back(b);
            answer.push_back(a);
            break;
        }
    }
    return answer;
}
