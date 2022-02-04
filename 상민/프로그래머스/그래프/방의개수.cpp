#include <string>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> cod;

set<pair<cod, cod>> e;
set<cod> v;

pair<cod, cod> bfinsert(cod a, cod b)
{
  if(a > b)
    return {a, b};
  return {b, a};
}

cod dir[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int solution(vector<int> arrows)
{
    int answer = 0;

    cod start = {0, 0};
    v.insert(start);

    for(int adx = 0; adx < arrows.size(); adx++)
    {
      cod move = dir[arrows[adx]];
      cod a = {start.first + move.first, start.second + move.second};
      e.insert(bfinsert(start, a));
      v.insert(a);

      cod b = {a.first + move.first, a.second + move.second};
      e.insert(bfinsert(a, b));
      v.insert(b);

      start = b;
    }

    return 1-v.size() + e.size();
}
