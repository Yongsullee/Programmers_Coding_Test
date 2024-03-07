/*
    문제 : 이후의 시간들 중 가격이 떨어진 순간을 제외한 나머지 시간들이 몇 초인지 저장하고, 반환합니다.
    설명
            1. stack을 활용한 전형적인 히스토그램 문제입니다.
            2. 다만, prices[i] > prices[s.top()] 임에도 불구하고, 앞에 위치한 price는 prices[s.top()]을 카운팅할 수 있습니다.
            3. 따라서, 주어진 데이터 목록을 정순으로 순회하며, 스택에 푸시하고 현재 위치 값과 s.top() 값을 비교하고, 결과 값을 계산하는 기준을 현재 값에서 s.top() 값으로 시선을 돌려야합니다.
            4. 마지막으로, stack에 남아 있는 데이터 항목들의 잔반 처리 또한 필요합니다.
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); ++i)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = (int)prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}