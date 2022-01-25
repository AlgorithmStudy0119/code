#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//소수 판별 함수
bool isPrime(int num){
    if(num < 2) return false;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0)  return false;
    }
    return true;
}

//숫자가 문자들로 만들 수 있는지 판별
bool isResult(int num, string str){
    string strNum = to_string(num);
    for(int i=0; i<strNum.size(); i++){
        int flag = false;
        for(int j=0; j<str.size(); j++){
            //일치하는 문자가 있는 경우
            if(strNum[i] == str[j]){
                flag = true;
                //해당 문자를 공백으로 바꿈
                str[j] = ' ';
                break;
            }
        }
        //일치하는 문자가 하나도 없는 경우
        if(!flag)   return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    //문자 큰 순서로 정렬
    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxNum = stoi(numbers);
    
    //가장 큰 수까지의 모든 숫자를 검사
    for(int i=0; i<=maxNum; i++){
        //소수이면서, 주어진 문자로 만들 수 있는 숫자인 경우
        if(isPrime(i) && isResult(i, numbers)){
            answer++;
        }
    }
    
    return answer;
}