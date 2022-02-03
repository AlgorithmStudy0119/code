#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 50;
bool visited[50];

//다른 문자가 1개인지 체크하는 함수
bool check_diff(string a, string b){
  int dif_cnt =0;

  for(int i=0; i<a.size();i++){
    if(a[i]!=b[i]){
      dif_cnt++;
    }
  }
    
  // 다른 문자가 1개인 경우
  if(dif_cnt==1){
    return true;
  }
    
  return false;
}

void dfs(string begin, string target,vector<string>words,int step){
  if(answer <= step)
    return;

  if(begin==target){
    answer = min(answer,step);
    return;
  }
  
  for(int i=0; i<words.size();i++){
    // 한개의 문자만 다르고 방문 하지 않은 단어이면 탐색 시작
    if(check_diff(begin,words[i]) && !visited[i]){
        visited[i]=true;
        dfs(words[i],target,words,step+1);
        visited[i]=false;
    }
  }
  
  return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,0);

    if(answer == 50)
        return 0;

    return answer;
}