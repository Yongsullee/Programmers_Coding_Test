#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ans = 0;
    
    // #0. map : pair< 인덱스, 체육복 갯수 >
    map<int, int> m;
    for(int i=1; i<=n; i++)
    {
        m.insert({i, 1});
    }
    // #1. reserve 목록의 인덱스에 +1
    for(int i=0; i<(int)reserve.size(); i++)
        m[reserve[i]]++;
    
    // #2. lost 목록의 인덱스에 -1
    for(int i=0; i<(int)lost.size(); i++)
        m[lost[i]]--;

    for(auto it = begin(m); it != end(m); it++)
    {
        // #1. 첫 번째 학생
        if(it == begin(m))
        {
            // #1. 체육복이 1개 이상일 경우, ans++
            if(it->second >= 1)
            {
                ans++;
            }
            // #2. 체육복이 없지만, 오른쪽 학생이 2개 이상일 경우, ans++
            else
            {
                if(next(it)->second >= 2)
                {
                    next(it)->second--;
                    ans++;
                }
            }
        }
        // #2. 마지막 학생
        else if(next(it) == end(m))
        {
            // #1. 체육복이 1개 이상일 경우, ans++
            if(it->second >= 1)
            {
                ans++;
            }
            // #2. 체육복이 없지만, 왼쪽 학생이 2개 이상일 경우, ans++
            else
            {
                if(prev(it)->second >= 2)
                {
                    ans++;
                }
            }
        }
        // #3. 두 번째 ~ 마지막 직전 학생 경우, 오른쪽 왼쪽 둘다 확인
        else
        {
            // #1. 체육복이 1개 이상일 경우, ans++
            if(it->second >= 1)
            {
                ans++;
            }
            // #2. 체육복이 없을 경우
            else
            {
                // #1. 왼쪽 학생이 체육복 2개 이상일 경우
                if(prev(it)->second >= 2)
                {
                    ans++;
                    continue;
                }
                // #2. 오른쪽 학생이 체육복 2개 이상일 경우
                if(next(it)->second >= 2)
                {
                    next(it)->second--;
                    ans++;
                }
            }
        }
    }
    
    return ans;
}