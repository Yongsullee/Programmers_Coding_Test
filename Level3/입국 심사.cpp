#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*

    0. 이분 탐색 활용을 위해 tiems를 오름차순 정렬
    1. 최소 시간 = 1, 최대 시간 = n * times의 마지막 원소

    2. while 문 순회하며 중간 시간 구하기.
    3. 중간 시간 동안 times의 각 심사 인원이 심사할 수 있는 최대 인원 총합 구하기
    4. 위에서 구한 총 합이 주어진 n보다 크거나 같을 경우, 결과 값을 업데이트하고 maxTime = minTime-1로 설정
    5. 위에서 구한 총 합이 주어진 n보다 작을 경우, minTime = midTime+1로 설정
    6. 2 ~ 5번 작업 반복, 데이터 유형 주의
*/

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    // #1. 오름차순 정렬
    sort(begin(times), end(times));

    // #2. n을 심사하는데 걸리는 최소 시간, 최대 시간
    long long minTime = 1;
    long long maxTime = n * (long long)times[(int)times.size() - 1];
    answer = maxTime;

    // #3. 이분 탐색
    while (minTime <= maxTime)
    {
        // #3-1. 중간 시간 구하기
        long long midTime = (maxTime + minTime) / 2;
        long long people = 0;

        // #3-2. 중간 시간 동안 심사 인원들이 심사할 수 있는 최대 인원 총합 구하기
        for (int i = 0; i < (int)times.size(); ++i)
        {
            people += midTime / times[i];
        }

        // #3-3. 중간 시간 동안 심사할 수 있는 인원의 총합과 주어진 n을 비교
        // #1. 총합이 n과 같거나 클 경우, 정답을 minTime으로 업데이트하고 maxTime = midTime-1로 갱신
        if (people >= n)
        {
            if (answer > midTime)
            {
                answer = midTime;
            }
            maxTime = midTime - 1;
        }
        // #2. 총합이 n보다 작을 경우, minTime = midTime+1로 갱신
        else
        {
            minTime = midTime + 1;
        }
    }

    return answer;
}