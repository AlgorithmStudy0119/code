#include <string>
#include <iostream>
#include <map>
#include <math.h>
#include <iomanip>

using namespace std;

//한 줄에 하나의 나무 종 이름이 주어짐

int main(){
    map<string, double> trees;
    double cnt=0;
    string str;

    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (getline(cin, str)) {
        trees[str]++;
        cnt++;
    }

    cout << fixed << setprecision(4); // 소수점 넷째자리

    for(auto pair : trees){
        cout << pair.first << " " <<round((pair.second/cnt)*100 << endl;
    }
   
}