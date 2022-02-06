#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;

    int dx[] = { 0,1,1,1,0,-1,-1,-1 }; // 1,2,3,4,5,6,7
    int dy[] = { 1,1,0,-1,-1,-1,0,1 };
    // 정점 map, 간선 map
    map<pair<int, int>, bool> node_visited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;

    int x = 0;
    int y = 0;

    node_visited[{x, y}] = true;
    for (int i = 0;i < arrows.size();i++) {
        // 표시되지 않는 정점 관리
        for (int j = 0;j < 2;j++) {
            int nx = x + dx[arrows[i]];
            int ny = y + dy[arrows[i]];
            // 방 생성 : 방문한 정점 재방문(선 중복X)
            if (node_visited[{nx, ny}] == true && edge_visited[{ {x, y}, { nx,ny }}] == false) {
                edge_visited[{ {x, y}, { nx,ny }}] = true;
                edge_visited[{ {nx, ny}, { x,y }}] = true;
                answer++;
                x = nx;
                y = ny;
                continue;
            }

            node_visited[{nx, ny}] = true;
            edge_visited[{ {x, y}, { nx,ny }}] = true;
            edge_visited[{ {nx, ny}, { x,y }}] = true;
            x = nx;
            y = ny;
        }

    }

    return answer;
}
