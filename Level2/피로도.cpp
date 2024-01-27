#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxDungeon;

void dfs(int leftFatigue, int cnt, const int &maxFatigue, vector<vector<int>> &dungeons,
         vector<bool> &visited)
{
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (!visited[i] && leftFatigue >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(leftFatigue - dungeons[i][1], cnt + 1, maxFatigue, dungeons, visited);
            visited[i] = false;
        }
    }

    maxDungeon = max(maxDungeon, cnt);
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> visited(dungeons.size(), false);

    dfs(k, 0, k, dungeons, visited);

    return maxDungeon;
}