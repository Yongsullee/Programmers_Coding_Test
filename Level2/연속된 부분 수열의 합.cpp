/*

    [문제]  :   부분 수열의 합 중 주어진 값과 일치하며, 그 길이가 가장 짧고 시작 인덱스가 가장 앞에 있는 부분 수열 찾기

    [풀이]  :   투 포인터 알고리즘(수열 내 부분 수열의 누적합 찾기) 활용하는 문제

*/

#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int left = 0;
    int right = 0;
    int sum = 0;
    int min_length = INT_MAX;
    
    answer.resize(2, -1);
    
    while(right <= sequence.size() && left < sequence.size())
    {
        if(sum >= k || right == sequence.size())
        {
            if(sum == k && right-left+1 < min_length)
            {
                min_length = right-left+1;
                answer[0] = left;
                answer[1] = right-1;
            }
            sum -= sequence[left++];
        }
        else
        {
            sum+= sequence[right++];
        }
    }
    
    return answer;
    
}