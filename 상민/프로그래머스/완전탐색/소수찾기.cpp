#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

bool prime(int num)
{
  if(num == 1)
    return false;

  for(int idx = 2; idx <= sqrt(num); idx++)
  {
    if(num % idx == 0)
      return false;
  }
  return true;
}


int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();

    vector<char> num;
    set<string> numset;
    set<string> check;

    for(int idx = 0; idx < len; idx++)
      num.push_back(numbers[idx]);

    sort(num.begin(), num.end());

    do{
      string curr = "";
      for(int idx = 0; idx < len; idx++)
        curr += num[idx];
      numset.insert(curr);
    }while(next_permutation(num.begin(), num.end()));


    for(auto iter = numset.begin(); iter != numset.end(); iter++)
    {
      for(int cnt = 1; cnt <= len; cnt++)
      {
        for(int start = 0; start + cnt <= len; start++)
        {
          string curr = (*iter).substr(start, start + cnt);
          if(check.find(curr) == check.end())
            check.insert(curr);
        }
      }
    }

    for(auto iter = check.begin(); iter != check.end(); iter++)
    {
      if((*iter)[0] == '0')
        continue;

      if(prime(stoi(*iter)))
        answer++;
    }

    return answer;
}
