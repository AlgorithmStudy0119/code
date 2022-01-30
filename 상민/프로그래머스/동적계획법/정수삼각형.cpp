#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for(int hdx = 1; hdx < triangle.size(); hdx++)
    {
        for(int rdx = 0; rdx < triangle[hdx].size(); rdx++)
        {
            if(rdx == 0)
            {
                triangle[hdx][rdx] += triangle[hdx-1][rdx];
                continue;
            }
            if(rdx == triangle[hdx].size()-1)
            {
                triangle[hdx][rdx] += triangle[hdx-1][rdx-1];
                continue;
            }

            triangle[hdx][rdx] += max(triangle[hdx-1][rdx], triangle[hdx-1][rdx-1]);
        }
    }

    for(int rdx = 0; rdx < triangle[triangle.size()-1].size(); rdx++)
    {
        answer = max(answer, triangle[triangle.size()-1][rdx]);
    }


    return answer;
}
