#include <iostream>
#include <map>
#include <string.h>
using namespace std;


int main()
{
  cout << fixed;
  cout.precision(4);
  map<string, int> treelist;

  string input;
  int cnt = 0;

  while(!cin.eof())
  {
    getline(cin, input);
    treelist[input] += 1;
    cnt += 1;
  }

  for(auto tree : treelist)
  {
    float percent = ((float)(tree.second) / (float)(cnt)) * 100;

    cout << tree.first << " " << percent << '\n';
  }


}
