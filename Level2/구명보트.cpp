#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 오름차순 정렬
    sort(begin(people), end(people));
    
    // 투 포인터
    int left = 0;
    int right = people.size()-1;
    
    while(left <= right)
    {
        // 남아 있는 인원 중 가장 가벼운 인원과 가장 무거운 인원이 1개의 구명보트에 함께 탈수 있는지 체크합니다.
        if(people[left] + people[right] <= limit)
        {
            // #1.  2명이 1개의 보트에 함께 탈 수 있다면, left 포인터를 오른쪽으로 한 칸 이동합니다.
            //      즉, left+1 과 right-1 되며, 해당 루프가 일찍 끝나게 되어 answer++가 더 적게 수행되어,
            //      최종적으로 최소 보트 개수를 찾을 수 있습니다.
            left++;
        }
        // #2. right 포인터를 왼쪽으로 한 칸 이동시킵니다.
        right--;
        answer++;
    }
    
    return answer;
}