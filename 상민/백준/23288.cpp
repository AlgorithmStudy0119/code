#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;

// 아래 위 앞 뒤 동 6, 1,
int dice[6] = {6, 1, 5, 2, 3, 4};
cod dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
int N, M, K;
int map[20][20];
bool visit[20][20];
queue<cod> lst;

void dice_move(int move)
{
  int d = dice[0];
  int t = dice[1];
  int f = dice[2];
  int r = dice[3];
  int e = dice[4];
  int w = dice[5];

  if(move == 0)
  {
    dice[0] = r;
    dice[1] = f;
    dice[2] = d;
    dice[3] = t;
  }
  if(move == 2)
  {
    dice[0] = f;
    dice[1] = r;
    dice[2] = t;
    dice[3] = d;
  }
  if(move == 1)
  {
    dice[0] = e;
    dice[1] = w;
    dice[4] = t;
    dice[5] = d;
  }
  if(move == 3)
  {
    dice[0] = w;
    dice[1] = e;
    dice[4] = d;
    dice[5] = t;
  }
}

int valuexy(cod input)
{
  int value = 0;
  memset(visit, 0, sizeof(visit));
  lst.push(input);
  visit[input.first][input.second] = true;

  while(!lst.empty())
  {
    cod curr = lst.front();
    value++;
    lst.pop();

    for(int ddx = 0; ddx < 4; ddx++)
    {
      cod next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
        continue;

      if(!visit[next.first][next.second] && map[next.first][next.second] == map[input.first][input.second])
      {
        lst.push(next);
        visit[next.first][next.second] = true;
      }
    }
  }
  return value;
}


int main()
{
  cin >> N >> M >> K;

  for(int ndx = 0; ndx < N; ndx++)
  {
    for(int mdx = 0; mdx < M; mdx++)
      cin >> map[ndx][mdx];
  }

  cod start = {0, 0};
  int move = 1;
  int result = 0;

  for(int kdx = 0; kdx < K; kdx++)
  {
    cod next = {start.first + dir[move].first, start.second + dir[move].second};

    if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
    {
      move = (move + 2) % 4;
      next = {start.first + dir[move].first, start.second + dir[move].second};
    }

    dice_move(move);

    if(dice[0] > map[next.first][next.second])
      move = (move + 1) % 4;

    if(dice[0] < map[next.first][next.second])
      move = (move + 3) % 4;

    result += valuexy(next) * map[next.first][next.second];
    start = next;
  }

  cout << result;
}
