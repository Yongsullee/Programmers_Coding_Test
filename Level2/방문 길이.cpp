#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;

p cPos = {0, 0};
map<char, p> d = {
    {'U', {1, 0}},
    {'D', {-1, 0}},
    {'R', {0, 1}},
    {'L', {0, -1}}};

struct Path
{
    p u, v;
    Path(p _u, p _v) : u(_u), v(_v) {}
    ` bool CheckIsVisited(p a, p b)
    {
        if (a == u && b == v)
            return true;
        else if (b == u && a == v)
            return true;
        else
            return false;
    }
};

vector<Path> visitedPath;

int solution(string dirs)
{
    int ans = 0;

    for (int i = 0; i < (int)dirs.size(); ++i)
    {
        int ny = cPos.first + d[dirs[i]].first;
        int nx = cPos.second + d[dirs[i]].second;

        // #1. 벗어난 경로인지 체크
        if (ny < -5 || ny > 5 || nx < -5 || nx > 5)
            continue;

        // #2. 해당 경로 방문 여부 확인
        bool checkIsVisited = false;
        for (auto &path : visitedPath)
        {
            if (path.CheckIsVisited({cPos.first, cPos.second}, {ny, nx}))
                checkIsVisited = true;
        }

        // #3. 경로 카운트 추가 여부 확인 : 새로운 경로 추가 및 경로 카운팅
        if (!checkIsVisited)
        {
            visitedPath.push_back(Path(cPos, {ny, nx}));
            ans++;
        }

        cPos = {ny, nx};
    }

    return ans;
}