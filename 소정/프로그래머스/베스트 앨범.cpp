#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//베스트 앨범에 들어갈 노래의 고유 번호 순서대로 리턴

//1. 가장 많이 재생된 장르 알아내기
//2. 가장 많이 재생된 노래 알아내기

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    
    map<string, int> genre_list;
    map<string, map<int, int>> music_list;
    
    for(int i=0; i<genres.size(); i++){
        genre_list[genres[i]] += plays[i];
        music_list[genres[i]][i] = plays[i];
    }
    
    while(genre_list.size() > 0){
        int max = 0;
        string genre="";

        for(auto pair : genre_list){
            if(max < pair.second){
                max = pair.second;
                genre = pair.first;
            }
        }
        
        for(int i=0; i<2; i++){
            int max_play = 0, idx = -1;
            for(auto pair : music_list[genre]){
                if(max_play < pair.second){
                    idx = pair.first;
                    max_play = pair.second;
                }
            }
            if(idx == -1) break;
            answer.push_back(idx);
            music_list[genre].erase(idx);
            
        }
        genre_list.erase(genre);        
    }

    return answer;
}