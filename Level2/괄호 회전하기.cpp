#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool IsValid(string s)
{
    stack<char> st;

    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() == '(')
                st.pop();
            else if (s[i] == '}' && st.top() == '{')
                st.pop();
            else if (s[i] == ']' && st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < (int)s.size(); ++i)
    {
        string tmp = s;
        rotate(tmp.begin(), tmp.begin() + i, tmp.end());
        if (IsValid(tmp))
            answer++;
    }

    return answer;
}
