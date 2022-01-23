#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//서로 다른 옷의 조합의 수 return
//clothes => [의상 이름, 의상 종류]

int solution(vector<vector<string>> clothes) {
    
    map<string, int> hm;
    
    for(int i=0; i<clothes.size(); i++){
        hm[clothes[i][1]]++;
    }

    int answer = 1;
    for(auto pair : hm){
        answer *= (pair.second+1);
    }
    
    return answer-1;
}