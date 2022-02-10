#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    for(int idx = 0; idx < skill.size(); idx++)
    {
      int type = skill[idx][0];
      int r1 = skill[idx][1]
      int c1 = skill[idx][2];
      int r2 = skill[idx][3]
      int c2 = skill[idx][4];
      int deg = skill[idx][5];

      for(int rdx = r1; rdx <= r2; rdx++)
      {
        for(int cdx = c1; cdx <= c2; cdx++)
          board[rdx][cdx] += ((type == 2)? deg : -deg);
      }
    }

    for(int rdx = 0; rdx < board.size(); rdx++)
    {
      for(int cdx = 0; cdx < board[0].size(); cdx++)
      {
        if(board[rdx][cdx] > 0)
          answer++;
      }
    }


    return answer;
}
