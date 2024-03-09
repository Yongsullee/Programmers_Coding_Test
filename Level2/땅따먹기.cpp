/*
    @문제 : 서로 다른 '열'을 밟으며, 각 행을 지나며 쌓인 총 합이 최대가 되는 수
    @설명
            1. BFS 혹은 DFS 활용할 경우, 시간 초과 발생!
            2. DP 활용
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int row = 1; row < land.size(); ++row)
    {
        for (int col = 0; col < land[row].size(); ++col)
        {
            int maxVal = 0;
            for (int k = 0; k < land[row].size(); ++k)
            {
                if (k != col)
                    maxVal = max(maxVal, land[row - 1][k]);
            }
            land[row][col] += maxVal;
        }
    }

    for (int i = 0; i < land[0].size(); ++i)
    {
        answer = max(answer, land[land.size() - 1][i]);
    }

    return answer;
}