#include <string>
#include <vector>
#include <algorithm>

using namespace std;
    
vector<int> island(101);

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int getParent(int idx){
    if(island[idx]==idx)    return idx;
    return island[idx] = getParent(island[idx]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        island[i] = i;
    }
    
    //비용 적은 순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++){
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        //사이클이 안만들어지면 다리 추가
        if(start != end){
            answer += cost;
            island[end] = start;
        }
    }
    return answer;
}