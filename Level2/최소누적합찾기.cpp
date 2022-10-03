#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // 1. A -> 내림차순 정렬, B -> 오름차순 정렬
    sort(begin(A), end(A), greater<>());
    sort(begin(B), end(B));
    
    // 2. 각 배열의 동일 인덱스의 항목을 곱하고 누적합니다.
    int tmp;
    for(int i=0; i<A.size(); i++)
    {
        tmp = A[i] * B[i];
        answer += tmp;
    }

    return answer;
}