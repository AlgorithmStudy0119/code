#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0, min_answer = 0;
    int start = 0, end = distance;

    sort(rocks.begin(), rocks.end());

    
    vector<int> distances;      // 바위 사이 거리
    distances.push_back(rocks.at(0));
    for (int i = 1; i < rocks.size(); i++)
        distances.push_back(rocks.at(i) - rocks.at(i - 1));
    distances.push_back(distance - rocks.at(rocks.size() - 1));
    

    while (start <= end) {
        int mid = (start + end) / 2;
        int cnt = 0;    // 없앤 바위 개수
        int idx = 0;
        int left = 0;

        for (int i = 0; i < rocks.size(); i++) {

            /*
            if (rocks[i] - left >= mid) left = rocks[i];
            else cnt++;
            */
            
            if (idx != i) {
                int temp = 0;
                for (int j = idx; j <= i; j++) {
                    temp += distances[j];
                }
                if (temp < mid)
                    cnt++;
                else
                    idx = i + 1;
            }
            else {
                if (distances[i] < mid) {
                    cnt++;
                }
                else {
                    idx++;
                }
            }
            
        }

        if (cnt > n) {
            end = mid - 1;
        }
        else {
            answer = mid;
            if (min_answer < answer) min_answer = answer;
            start = mid + 1;
        }
    }


    return min_answer;
}
