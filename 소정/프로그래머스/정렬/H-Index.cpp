#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//논문 n개 중에서 h번 이상 인용된 논문이 h개 이상이고, 나머지 논문이 h번 이하로 인용되는 경우

int solution(vector<int> citations) {
    int answer = 0;
    
    //인용 횟수 오름차순 정렬
    sort(citations.begin(), citations.end());
    
    for(int i=0; i<citations.size(); i++){
        //현재 인덱스를 포함해서 남은 논문의 개수
        int Hidx = citations.size() - i;
        if(citations[i] >= Hidx)    return Hidx;
    }
    
    return answer;
}