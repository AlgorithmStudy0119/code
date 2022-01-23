#include <string>
#include <vector>
#include <map>

using namespace std;

//접두어 있으면 false, 아니면 true

bool solution(vector<string> phone_book) {
    
    map<string, int> hm;
    
    for(string s : phone_book){
        hm[s] = 1;
    }
    
    for(string phone_num : phone_book){
        for(int i=1; i<phone_num.size(); i++){
            if(hm[phone_num.substr(0,i)] == 1)
                return false;
        }
    }
    
    return true;
}