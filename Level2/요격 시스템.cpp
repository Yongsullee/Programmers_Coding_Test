/*

    [문제]  : 중복 구간을 최소로 하는 방법

    [설명]  : 주어진 구간들 중 중복 값을 갖는 구간들을 최대로 찾고, 그 횟수를 최소로하는 문제 

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(begin(targets), end(targets), [](vector<int> a, vector<int> b){
        return a[1] < b[1];
    });
    
    double prev_max = -1;
    for(int i=0; i<(int)targets.size(); i++)
    {
        // 다른 미사일 추가
        if(targets[i][0] >= prev_max)
        {
            answer++;
            prev_max = targets[i][1];
        }
    }
    
    return answer;
}