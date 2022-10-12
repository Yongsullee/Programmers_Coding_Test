/*
    이상하게 계속 틀림...허허..
    아래 코드는 정답!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    
    // 1. 오름차순 정렬
    sort(begin(d), end(d));
    
    // 2. 최소 값이 Budget보다 적으면 끝
    if(budget < d[0])
        return 0;
    
    // 2. 차례대로 누적 합 비교
    int num = 0;
    for(int i=0; i<d.size(); i++)
    {
        if(d[i] <= budget)
        {
            budget -= d[i];
            num++;
        }else
        {
            break;
        }
    }
    
    return num;
}