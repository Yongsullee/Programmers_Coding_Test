#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // pair < 현재 작업율, 작업의 개발 속도 >
    stack<pair<int, int>> s;

    for(int i=progresses.size()-1; i>=0; --i)
        s.push({progresses[i], speeds[i]});

    if(s.empty())
    {
        answer.push_back(0);
        return answer;
    }

    while(!s.empty())
    {
        // #1. s.top()의 남은 작업 기간 계산 
        int days = ceil((100 - s.top().first)/s.top().second);
        int cnt = 1;
        s.pop();
        // #2. 후순위 기능 중 현재 작업 기간 내 이미 끝나있는 작업들 계산
        while(!s.empty() && (ceil((100 - s.top().first)/s.top().second) <= days))
        {
            cnt++;
            s.pop();
        }

        answer.push_back(cnt);
    }

    return answer;
}