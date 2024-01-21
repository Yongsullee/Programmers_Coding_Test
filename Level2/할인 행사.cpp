#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // #1. 구입할 제품 + 개수 목록
    map<string, int> m;
    for(int i=0; i<want.size(); ++i)
        m[want[i]] = number[i];
    
    for(int i=0; i<=discount.size()-10; ++i)
    {
        // #2. i일 기준 10일 간의 할인 제품 목록
        map<string, int> mdiscount;
        for(int j=i; j<i+10; ++j)
        {
            mdiscount[discount[j]]++;
        }
        // #3. i일 기준 10일 간의 할인 제품과 정현이가 원하는 제품 개수 비교
        bool bPossible = true;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(mdiscount[it->first] < it->second)
            {
                bPossible = false;
                break;
            }
        }
        if(bPossible)
            answer++;
    }
    return answer;
}
