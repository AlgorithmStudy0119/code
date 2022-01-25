#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    //최소 시간=1, 최대 시간=가장 오래걸리는 심사관이 모든 사람을 처리할 경우
    long long min = 1; 
    long long max = *max_element(times.begin(), times.end()) * (long long)n;
    long long answer = max;
    
    while(min <= max){
        
        long long mid = (min+max)/2;
        
        //주어진 시간에 입국심사할 수 있는 모든 사람의 수
        long long cnt = 0;
        for(int i=0; i<times.size(); i++){
            cnt += mid / times[i];
        }
        
        if(cnt < n) min=mid+1;
        else{
            max = mid - 1;
            answer = mid;   
        }
    }
    
    return answer;
}