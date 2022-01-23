#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;

    for (int i = 0;i < commands.size();i++)
    {
        tmp.clear();
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        //int ans = b - a;

        //cout << "a : " << a << " b : " << b << " c : " << c;

        for (int j = a - 1; j < b;j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());

        //for (int k = 0;k < tmp.size();k++)
        //    cout << tmp[k] << " ";

        answer.push_back(tmp[c - 1]);
        //cout << endl;
    }


    return answer;
}