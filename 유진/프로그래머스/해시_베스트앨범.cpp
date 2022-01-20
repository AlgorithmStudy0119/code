#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool sorting(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

bool sorting2(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // key : 장르종류, value : 장르별 재생횟수 합
    map<string, int> genres_cnt;
    // 장르, (재생횟수, 고유번호)
    map<string, vector<pair<int, int>>> music;
    for (int i = 0;i < genres.size();i++) {
        genres_cnt[genres[i]] += plays[i];
        music[genres[i]].push_back({ plays[i],i });
    }

    // 재생횟수를 기준으로 내림차순 정렬
    for (auto& play : music) {
        sort(play.second.begin(), play.second.end(), sorting);
    }

    // 장르별 속한 노래 개수 내림차순 정렬
    vector<pair<string, int>> genres_cnt2;
    genres_cnt2.assign(genres_cnt.begin(), genres_cnt.end());
    sort(genres_cnt2.begin(), genres_cnt2.end(), sorting2);


    for (int i = 0;i < genres_cnt2.size();i++) {
        string gen_name = genres_cnt2[i].first; // 장르 이름
        for (int j = 0;j < 2 && j < music[gen_name].size();j++) { // 최대 2곡만 선택
            answer.push_back(music[gen_name][j].second);
        }
    }
    return answer;
}