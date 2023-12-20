// 오답 코드
#include <string>
#include <vector>
using namespace std;

void dfs(int cnt, const int &maxCnt, int &answer)
{
    if (cnt == maxCnt)
    {
        answer++;
        return;
    }
    else if (cnt > maxCnt)
    {
        return;
    }
    else
    {
        if (maxCnt - cnt < 2)
        {
            dfs(cnt + 1, maxCnt, answer);
        }
        else
        {
            dfs(cnt + 1, maxCnt, answer);
            dfs(cnt + 2, maxCnt, answer);
        }
    }
}

long long solution(int n)
{
    long long answer = 0;

    dfs(1, n, answer);
    dfs(2, n, answer);

    return answer % 1234567;
}

// 정답 코드

#include <string>
#include <vector>

using namespace std;

long long solution(int n)
{
    long long answer = 0;

    vector<long long> dp(2001, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }

    return dp[n];
}