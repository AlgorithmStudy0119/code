#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> type_count;
    unordered_map<string, int>::iterator iter;
    
    for(int i=0; i<clothes.size(); i++){
        string type = clothes[i][1];
        ++type_count[type];
    }
    
    for(iter = type_count.begin(); iter!= type_count.end(); iter++){
        int cnt = iter->second;
        answer *= (cnt+1);
    }
    
    return --answer;
}
