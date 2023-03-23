// 1. 첫 번째 답안, 효율성이 떨어져 탈락

#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int i;
    for(i=0; i<s.size()-1;)
    {
        if(s.size() <= 1) break;
        
        if(s[i] == s[i+1])
        {
            s.erase(i, 2);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    
    if(s.empty() == true) answer++;
    
    return answer;
}

// 2. 스택을 사용
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    if(s.size()%2 != 0) return answer;
    
    stack<char> stk;
    for(size_t i=0; i<s.size(); i++)
    {
        if(stk.empty() || stk.top() != s[i])
            stk.push(s[i]);
        else
            stk.pop();
    }
    
    if(stk.empty())
        answer++;
    
    return answer;
}