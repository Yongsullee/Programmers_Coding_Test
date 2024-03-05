/*
    @문제 : words 목록 중 현재 단어의 문자 중 1개만 바꿔서 변환 가능한 word로 지속적으로 변환하며,
            최종적으로, target 문자열이 되는 최소 변환 횟수를 찾는 문제입니다.
    @설명
            1. 먼저, words 목록의 각 문자열을 시작으로 dfs를 수행합니다.
            2. 이때, 현재 문자와 현재 word의 다른 문자가 1개일 때만 계속 진행합니다.
            3. 각 문자열의 방문 여부를 체크하고, 백트래킹을 위해 방문 여부를 true -> false로 복원시켜줍니다.
            4. 최종적으로, 현재 word가 target과 같은 문자열이 되었을 때, 그 변환 횟수와 현재 최소 변환 횟수를 비교하여, 최소 변홚 횟수를 업데이트해줍니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minChange = INT_MAX;

void dfs(int wordsIdx, int cnt, string str, const string &target, const vector<string> &words, vector<bool> &visited)
{

    int diffStrAndWords = 0;
    for (int i = 0; i < (int)str.size(); ++i)
    {
        if (str[i] != words[wordsIdx][i])
            diffStrAndWords++;
    }

    if (diffStrAndWords == 1)
    {
        cnt++;
        if (words[wordsIdx] == target)
        {
            minChange = min(minChange, cnt);
            return;
        }

        visited[wordsIdx] = true;
        for (int i = 0; i < (int)words.size(); ++i)
        {
            if (!visited[i])
                dfs(i, cnt, words[wordsIdx], target, words, visited);
        }
        visited[wordsIdx] = false; // 백트래킹
    }
    else
    {
        return;
    }
}

int solution(string begin, string target, vector<string> words)
{
    bool bCanChange = false;

    for (const auto &word : words)
    {
        if (word == target)
        {
            bCanChange = true;
            break;
        }
    }

    if (bCanChange)
    {
        for (int i = 0; i < (int)words.size(); ++i)
        {
            vector<bool> visited((int)words.size(), false);
            dfs(i, 0, begin, target, words, visited);
        }
    }
    else
    {
        return 0;
    }

    if (minChange == INT_MAX)
        return 0;
    else
        return minChange;
}
