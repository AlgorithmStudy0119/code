#include <string>
#include <vector>

using namespace std;

int cmp(int a, int b, int c){
    int temp = a;
    if(temp > b){
        return temp > c ? temp : c;        
    } else{
        return b > c ? b : c;
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3] = { 0 };
    
    vector<int>answer1{ 1,2,3,4,5 };
    vector<int>answer2{ 2,1,2,3,2,4,2,5 };
    vector<int>answer3{ 3,3,1,1,2,2,4,4,5,5 };
    
    for(int i=0; i<answers.size(); i++){
        if (answers[i] == answer1[i % 5]) count[0]++;
        if (answers[i] == answer2[i % 8]) count[1]++;
        if (answers[i] == answer3[i % 10]) count[2]++;
    }
    
    int max = cmp(count[0], count[1], count[2]);
    for(int i=0; i<3; i++){
        if(max == count[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}