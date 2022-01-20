#include <iostream>
using namespace std;


//각 도시별로 홍보하는데 드는 비용, 그 때 몇 명의 호텔 고객이 늘어나는지를 담은 배열

//호텔의 고객을 적어도 C명 늘이기 위해 형택이가 투자해야 하는 돈의 최솟값 구하기

// 늘릴 고객 : C명
// 홍보할 수 있는 도시의 개수 : N개
//C <=  1000, N<=20

//고객 12명, 2개 도시
//3원, 5명          //  6원, 10명      
//1원, 1명          //  2원, 2명  
//정답 : 8원

//각 도시에서 홍보할 때 대는 비용, 그 비용으로 얻을 수 있는 고객의 수를 담은 배열
int arr[20][2];
int sum[1001];
int cost;

//최솟값 구하는 재귀 함수
int result(int people, int city){

    int min_cost = 1000*100;

    if(people <= 0) return 0;
    else if (sum[people] > 0) return sum[people];
    else {
        for(int i=0; i< city; i++){
            cost = result(people - arr[i][1], city) + arr[i][0];
            min_cost = cost < min_cost ? cost : min_cost;
        }

        sum[people] = min_cost;
        return min_cost;
    }
}

int main(void){

    int C, N = 0;
    cin >> C >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    int answer = result(C, N);

    cout << answer;
      
}
