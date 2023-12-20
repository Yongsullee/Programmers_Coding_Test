#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    // #1. map을 통해 크기 별 귤의 개수를 구한다.
    map<int, int> m;
    for (int i = 0; i < (int)tangerine.size(); ++i)
        m[tangerine[i]]++;

    // #2. 우선순위 큐에 크기 별 개수를 삽입한다.
    priority_queue<int> pq;
    for (auto it = begin(m); it != end(m); ++it)
        pq.push(it->second);

    // #3. 우선순위 큐의 top을 꺼내며, k개수를 차감하며 0이하가 될때 까지 종류를 카운트한다.
    while (!pq.empty())
    {
        int num = pq.top();
        pq.pop();

        answer++;
        k -= num;
        if (k <= 0)
            break;
    }

    return answer;
}