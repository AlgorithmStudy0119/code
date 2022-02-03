#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    //현재 차가 나가는 거리
    int temp = routes[0][1];
    
    for(auto r : routes){
        
        //현재 차가 나간 후에 다음차가 들어오는 경우
        if(temp < r[0]){
            //카메라 설치
            answer++;
            //다음차로 갱신
            temp = r[1];
        }
        //현재 차보다 뒤차가 먼저 나가는 경우
        if(temp >= r[1]){
            //뒤차로 갱신
            temp = r[1];
        }
    }
    
    return answer;
}