#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
        
    //바위 위치 오름차순 정렬
    sort(rocks.begin(), rocks.end());
    
    int start = 0; 
    int end = distance;
    while(start <= end){
        //바위 사이의 거리
        int mid = (start + end)/2;
        
        //바위 제거 횟수
        int cnt = 0;
        
        int prev = 0;
        
        for(int i=0; i<rocks.size(); i++){
            //가장 가까운 바위와의 거리를 mid와 비교
            if(rocks[i]-prev >= mid)    prev = rocks[i];
            else cnt++;
        }
        
        //바위를 너무 많이 제거한 경우
        if(cnt > n) end = mid - 1;
        
        //바위를 덜 제거한 경우
        else{
            answer = max(answer,mid);
            start = mid + 1;
        }
    }
    return answer;
}
