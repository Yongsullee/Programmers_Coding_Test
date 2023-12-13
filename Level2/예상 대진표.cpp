#include <iostream>
#include <cstdlib>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // #1. a와 b의 참가자 번호가 같을 때 까지 2를 나누어준다.
    while (a != b)
    {
        // a가 첫 번째 부여받은 번호가 4라면, 다음 라운드에서 2를 부여받는다.
        a = (a + 1) / 2;
        // b가 첫 번째 부여받은 번호가 7라면, 다음 라운드에서 4를 부여받는다.
        b = (b + 1) / 2;
        answer++;
    }

    return answer;
}