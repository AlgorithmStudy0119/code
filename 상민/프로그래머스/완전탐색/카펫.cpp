#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = (brown + 4) / 2;

    int mul = brown + yellow;

    for(int idx = 1; idx < sum; idx++)
    {
      if(idx * (sum - idx) == mul)
      {
        answer.push_back(sum - idx);
        answer.push_back(idx);
        break;
      }
    }

    return answer;
}
