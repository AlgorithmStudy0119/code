#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//암호(L개의 알파벳 소문자) = 최소 1개 모음 + 최소 2개 자음
//알파벳이 증가하는 순서

int L,C;    // L : 암호 길이, C : 문자 개수
vector<char> vowel;     //모음
vector<char> consonant;     //자음
vector<string> result;  //결과
map<string, bool> visited;

//모음인지 검사
bool is_vowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')   return true;
    else return false;
}

//모음벡터 인덱스, 자음벡터 인덱스, 모음 개수, 자음 개수, 만든 문자열
void getResult(int vIdx, int cIdx, int vCnt, int cCnt, string s){
    
    //모든 조건 만족할 경우
    if(s.length()==L && vCnt >=1 && cCnt >=2){
        //알파벳 정렬
        sort(s.begin(), s.end());
        //result에 넣은 적이 없으면
        if(visited.count(s) == 0){
            visited[s] = true;
            result.push_back(s);
        }
        return;
    }

    //길이만 같고, 개수 조건은 만족하지 못할 경우
    if(s.length() == L){
        return;
    }

    //모든 조합 검사
    for(int i=vIdx+1; i<vowel.size(); i++){
        getResult(i, cIdx, vCnt+1, cCnt, s+vowel[i]);
    }
    for(int i=cIdx+1; i<consonant.size(); i++){
        getResult(vIdx, i, vCnt, cCnt+1, s+consonant[i]);
    }

}

int main(){

    cin >> L >> C;

    for(int i=0; i<C; i++){
        char s;
        cin >> s;
        if(is_vowel(s)) vowel.push_back(s);
        else consonant.push_back(s);
    }
    
    sort(vowel.begin(), vowel.end());
    sort(consonant.begin(), consonant.end());

    getResult(-1,-1,0,0,"");

    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}