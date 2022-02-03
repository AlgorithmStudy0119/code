#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    //두번째 줄부터
    for (int i = 1; i < triangle.size(); i++) { 
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j - 1 < 0)
                //오른쪽 위
                triangle[i][j] += triangle[i - 1][j]; 
            else if (j == i)
                //왼쪽 위
                triangle[i][j] += triangle[i - 1][j - 1]; 
            else
                //오른쪽 위, 왼쪽 위 중 더 큰 값
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]); 
        }
    }
    
    //바닥에서 가장 큰 수
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end()); 

    return answer;
}