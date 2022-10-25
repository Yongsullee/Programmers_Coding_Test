/*
    1.   For 문을 돌면서 String의 특정 문자 제거하기

    :   For문 안에서 직접 str.erase()를 활용하면 항목간의 순서가 변경되어
        제대로 삭제되지 않는 경우가 발생합니다. 따라서, STL 알고리즘의 remove_if를 활용합니다.

    2.   auto it = remove_if(begin(s), end(s), Pred)

    :   remove_if 의 세 번째 인자는 Predicate 함수입니다!!

    3.  10진수 -> 2진수 변환 알고리즘

    : 아래 decToBin을 참고해주세요!

*/

#include <string>
#include<vector>
#include <algorithm>

    using namespace std;

bool Pred(char c)
{
    return c == '0';
}

vector<int> solution(string s)
{
    vector<int> answer;

    int delete0Cnt = 0;
    int decToBinCnt = 0;

    vector<int> tmpV;

    while (s != "1")
    {
        // 1. 0 제거, for 문을 돌면서 삭제하면 String에 직접적인 변화
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                ++delete0Cnt;
            }
        }

        auto it = remove_if(begin(s), end(s), Pred);
        s.erase(it, end(s));

        // 2. size 길이 -> 이진 변환
        int n = (int)s.size();
        while (n > 0)
        {
            int tmp = n % 2;
            tmpV.push_back(tmp);

            n /= 2;
        }

        string str = "";
        for (int i = 0; i < tmpV.size(); i++)
        {
            str += (tmpV[i] + '0');
        }

        s = str;

        decToBinCnt++;
        tmpV.clear();
    }

    answer.push_back(decToBinCnt);
    answer.push_back(delete0Cnt);

    return answer;
}