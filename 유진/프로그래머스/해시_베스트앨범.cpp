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
    // key : �帣����, value : �帣�� ���Ƚ�� ��
    map<string, int> genres_cnt;
    // �帣, (���Ƚ��, ������ȣ)
    map<string, vector<pair<int, int>>> music;
    for (int i = 0;i < genres.size();i++) {
        genres_cnt[genres[i]] += plays[i];
        music[genres[i]].push_back({ plays[i],i });
    }

    // ���Ƚ���� �������� �������� ����
    for (auto& play : music) {
        sort(play.second.begin(), play.second.end(), sorting);
    }

    // �帣�� ���� �뷡 ���� �������� ����
    vector<pair<string, int>> genres_cnt2;
    genres_cnt2.assign(genres_cnt.begin(), genres_cnt.end());
    sort(genres_cnt2.begin(), genres_cnt2.end(), sorting2);


    for (int i = 0;i < genres_cnt2.size();i++) {
        string gen_name = genres_cnt2[i].first; // �帣 �̸�
        for (int j = 0;j < 2 && j < music[gen_name].size();j++) { // �ִ� 2� ����
            answer.push_back(music[gen_name][j].second);
        }
    }
    return answer;
}