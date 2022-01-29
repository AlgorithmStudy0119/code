#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int iter = 0;

    for(int idx = iter; idx + k < number.length(); idx++)
    {
      int ptr = 0;
      int max = 0;
      for(int jdx = idx; jdx <= idx + k; jdx++)
        max = (max > number[jdx])? max : number[jdx];

      if(number[idx] == max)
        continue;

      for(ptr = idx; number[ptr] != max; ptr++)
        number[ptr] = 'A';

      k -= (ptr - idx);
      iter += (ptr - idx);
    }

    iter = number.length()-1;
    while((k--) != 0)
      number[iter--] = 'A';

    for(int idx = 0; idx < number.length(); idx++)
    {
      if(number[idx] != 'A')
        answer += number[idx];
    }

    return answer;
}
