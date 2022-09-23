/*
    *   #include <cctype> 제공 함수 주의할 점

    :   islower(), isdigit(), isupper() 등의 함수는 반환 값이 int입니다.
        if(islower(str[i]) == true)는 정상적으로 수행되지 않습니다!
*/

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool changeCheck = true;

    if (isdigit(s[0]))
    {
        answer += s[0];
    }
    else
    {
        answer += toupper(s[0]);
    }

    changeCheck = false;
    for (int i = 1; i < s.size(); i++)
    {
        // 1. 공백
        if (s[i] == ' ')
        {
            changeCheck = true;
            answer += s[i];
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            changeCheck = false;
            answer += s[i];
        }
        else
        {
            if (changeCheck == true)
            {
                answer += toupper(s[i]);
            }
            else
            {
                answer += tolower(s[i]);
            }
            changeCheck = false;
        }
    }

    return answer;
}