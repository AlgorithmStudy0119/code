#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;


int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;
  stack<int> arr[N];


  int input;
  for(int idx = 0; idx < N; idx++)
  {
    for(int jdx = 0; jdx < N; jdx++)
    {
      cin >> input;
      arr[jdx].push(input);
    }
  }

  for(int cnt = 0; cnt < N; cnt++)
  {
    int popidx = 0;

    for(int iter = 1; iter < N; iter++)
    {
      if(arr[popidx].top() < arr[iter].top())
        popidx = iter;
    }

    if(cnt == N-1)
    {
      cout << arr[popidx].top();
      return 0;
    }
    arr[popidx].pop();
  }



}
