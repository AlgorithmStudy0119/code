#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //무게 순 오름차순 정렬
    sort(people.begin(), people.end()); 
    
    int start = 0, end = people.size()-1;
    
    while(start <= end){
        //가장 가벼운 사람 + 가장 무거운 사람 <= 무게 제한
        if(people[start] + people[end] <= limit){
            start++;
            end--;
        }
        else {
            //가장 무거운 사람 혼자 타기
            end--;
        }
        answer++;
    }

    return answer;
}