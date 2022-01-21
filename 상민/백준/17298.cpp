#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> input(N);

  for(int idx = 0; idx < N; idx++)
    cin >> input[idx];

  vector<int> nge(N);
  stack<int> stack;

  stack.push(0);
  int ptr = 1;

  while(ptr < N)
  {
    while(!stack.empty() && input[ptr] > input[stack.top()])
    {
      nge[stack.top()] = input[ptr];
      stack.pop();
    }
    stack.push(ptr);
    ptr++;
  }

  while(!stack.empty())
  {
    nge[stack.top()] = -1;
    stack.pop();
  }

  for(int idx = 0; idx < N; idx++)
    cout << nge[idx] << " ";

}
