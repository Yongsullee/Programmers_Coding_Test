// #1. 효율성 테스트 실패

// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;

// typedef pair<int, int> p;

// int dy[] = {1, -1, 0, 0};
// int dx[] = {0, 0, 1, -1};

// int solution(vector<vector<int>> maps)
// {
//     int endY = maps.size() - 1;
//     int endX = maps[0].size() - 1;

//     // 우선순위 큐 선언, pair < 최단 경로 값, 정점 >
//     priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> pq;
//     // 각 정점의 최단 경로 값
//     vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), INT_MAX));
//     // 우선순위 큐에 시작 정점 삽입
//     pq.push({maps[0][0], {0, 0}});
//     // 시작 정점의 최단 경로 값 초기화
//     dist[0][0] = 1;

//     while (!pq.empty())
//     {
//         int cy = pq.top().second.first;
//         int cx = pq.top().second.second;
//         int cw = pq.top().first;
//         pq.pop();

//         if (cw > dist[cy][cx])
//             continue;

//         for (int i = 0; i < 4; ++i)
//         {
//             int ny = cy + dy[i];
//             int nx = cx + dx[i];
//             int nw = cw + maps[ny][nx];

//             if (ny < 0 || ny > endY || nx < 0 || nx > endX || maps[ny][nx] == 0 || dist[ny][nx] < nw)
//                 continue;

//             dist[ny][nx] = nw;
//             pq.push({nw, {ny, nx}});
//         }
//     }

//     if (dist[endY][endX] != INT_MAX)
//         return dist[endY][endX];
//     else
//         return -1;
// }

// #2. 정답 코드, BFS 활용
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;

int minCost;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps)
{

    int endY = maps.size() - 1;
    int endX = maps[0].size() - 1;

    // 큐 선언
    queue<p> q;
    // 각 정점의 최단 경로 값
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), -1));

    // 시작 정점을 큐에 삽입 + 시작 정점의 최단 경로 값 업데이트
    q.push({0, 0});
    dist[0][0] = maps[0][0];

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny > endY || nx < 0 || nx > endX || maps[ny][nx] == 0)
                continue;

            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    if (dist[endY][endX] != INT_MAX)
        return dist[endY][endX];
    else
        return -1;
}