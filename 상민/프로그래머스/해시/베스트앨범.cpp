#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

map<string, int> genrelist;


bool t_compare(tuple<string, int, int> a, tuple<string, int, int> b)
{
    int a_plays = genrelist.find(get<0>(a))->second;
    int b_plays = genrelist.find(get<0>(b))->second;

    if(a_plays != b_plays)
      return a_plays > b_plays;

    else if(get<1>(a) != get<1>(b))
      return get<1>(a) > get<1>(b);

    return  get<2>(a) < get<2>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<tuple<string, int, int>> musiclist;

    for(int idx = 0; idx < genres.size(); idx++)
    {
        genrelist[genres[idx]] += plays[idx];
        musiclist.push_back({genres[idx], plays[idx], idx});
    }

    sort(musiclist.begin(), musiclist.end(), t_compare);
    string prev; int cnt = 0;

    for(int idx = 0; idx < musiclist.size();)
    {
        if(idx == 0)
        {
            answer.push_back(get<2>(musiclist[idx]));
            prev = get<0>(musiclist[idx]);
            idx++;
            cnt += 1;
            continue;
        }
        else
            prev = get<0>(musiclist[idx-1]);

        if(prev == get<0>(musiclist[idx]))
        {
            if(cnt == 2)
            {
                while(prev == get<0>(musiclist[idx]))
                    idx++;
                cnt = 0;
            }
            else
            {
                answer.push_back(get<2>(musiclist[idx]));
                cnt += 1;
                idx++;
            }
        }
        else
        {
            answer.push_back(get<2>(musiclist[idx]));
            cnt = 1;
            idx++;
        }
    }

    return answer;
}
