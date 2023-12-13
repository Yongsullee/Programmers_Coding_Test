#include <string>
#include <vector>

using namespace std;

// /#1. DFS 정의, 다음 Index에 대해 두 개의 DFS를 재귀적으로 수행
void DFS(int &answer, int plusOrMinus, int curIdx, const int &target, int sum, vector<int> &numbers)
{
    sum += (plusOrMinus * numbers[curIdx]);
    if (curIdx == numbers.size() - 1)
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }

    DFS(answer, 1, curIdx + 1, target, sum, numbers);
    DFS(answer, -1, curIdx + 1, target, sum, numbers);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    int sum = 0;

    // #1. 양수 버전의 DFS 수행
    DFS(answer, 1, 0, target, sum, numbers);
    // #2. 음수 버전의 DFS 수행
    DFS(answer, -1, 0, target, sum, numbers);

    return answer;
}
