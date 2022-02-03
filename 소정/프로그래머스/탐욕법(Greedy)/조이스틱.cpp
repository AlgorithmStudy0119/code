#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    //상하 이동횟수
    for(auto c : name)
        answer += min(c-'A', 'Z'-c+1);
    
    int len = name.length();
    
    //좌우 이동횟수의 초기값 = 최대 이동횟수
    int move = len - 1;
    
    //좌우 이동횟수
    for(int i=0; i<len; i++){
        int target = i+1;
        
        //A로만 이루어진 문자열 찾기
        while(target < len && name[target] == 'A'){
            target++;
        }
        move = min(move, i+(len-target) + min(i, len-target));
    }
    answer += move;

    return answer;
}