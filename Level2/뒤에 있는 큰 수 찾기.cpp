/*
*   [문제]  : 현재 위치의 원소보다 오른쪽에 위치하며, 더 큰 수를 찾는 문제
*
*   [설명]  : BOJ_17298 문제와 동일한 문제, 배열을 역순회하며 stack을 오름차순 유지하며 top과 비교하는 문제
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;

    answer.resize(numbers.size(), -1);
    
    for(int i= numbers.size()-1; i>= 0; i--)
    {
        while(!s.empty() && numbers[i] >= s.top())
        {
            s.pop();
        }
        
        if(!s.empty()) 
            answer[i] = s.top();
        
        s.push(numbers[i]);
    }
    
    return answer;
}