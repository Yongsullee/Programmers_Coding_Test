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

int solution(string dirs)
{
    int ans = 0;

    for (int i = 0; i < (int)dirs.size(); ++i)
    {
        int ny = cPos.first + d[dirs[i]].first;
        int nx = cPos.second + d[dirs[i]].second;

        if (ny < -5 || ny > 5 || nx < -5 || nx > 5)
            continue;

        // #1. cPos -> nPos

        // #2. nPos -> cPos

        cPos = {ny, nx};
    }

    return ans;
}