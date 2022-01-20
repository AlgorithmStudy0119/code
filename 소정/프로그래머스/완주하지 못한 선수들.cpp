#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string, int> hm;
    for(string name : participant) {
        hm[name]++;
    }
    
    for(string name : completion) {
        hm[name]--;
    }
    
    for(auto pair : hm) {
        if(pair.second != 0)
            return pair.first;
    }
    
} 
