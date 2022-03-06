#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{

    vector<int> answer;
    bool winNum[46] = {
        0,
    };
    map<int, int> rankSystem;
    int lowestCnt = 0;
    int highestCnt = 0;
    int zeroCnt = 0;

    rankSystem.insert({6, 1});
    rankSystem.insert({5, 2});
    rankSystem.insert({4, 3});
    rankSystem.insert({3, 4});
    rankSystem.insert({2, 5});

    for (auto it = win_nums.begin(); it != win_nums.end(); it++)
        winNum[(*it)] = true;

    for (auto it = lottos.begin(); it != lottos.end(); it++)
    {
        if ((*it) == 0)
        {
            zeroCnt++;
        }
        if (winNum[(*it)] == true)
        {
            lowestCnt++;
        }
    }
    highestCnt = lowestCnt + zeroCnt;

    if (highestCnt <= 1)
    {
        answer.push_back(6);
    }
    else
    {
        for (auto it = rankSystem.begin(); it != rankSystem.end(); it++)
        {
            if (it->first == highestCnt)
            {
                answer.push_back(it->second);
            }
        }
    }

    if (lowestCnt <= 1)
    {
        answer.push_back(6);
    }
    else
    {
        for (auto it = rankSystem.begin(); it != rankSystem.end(); it++)
        {
            if (it->first == lowestCnt)
            {
                answer.push_back(it->second);
            }
        }
    }

    return answer;
}