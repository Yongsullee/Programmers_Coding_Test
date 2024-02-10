/*
    @문제 : 네트워크를 형성하는 경로의 개수
    @설명
            1. 각 정점에 대하여 깊이 우선 탐색을 수행합니다.
            2. 각 정점을 기준으로 깊이 우선 탐색을 수행하며 방문한 정점에 대하여 방문 여부를 체크합니다.
            2. 방문 여부가 참인 정점은 이후 탐색 작업에서 제외되며, 다른 네트워크를 찾아냅니다.
*/

#include <string>
#include <vector>

using namespace std;

int network;
vector<bool> visited;

void dfs(int cur, vector<vector<int>> &graph)
{
    visited[cur] = true;

    for (int i = 0; i < (int)graph.size(); ++i)
    {
        if (i == cur)
            continue;

        if (graph[cur][i] != 0 && !visited[i])
        {
            dfs(i, graph);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{

    visited.resize(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, computers);
            network++;
        }
    }

    return network;
}