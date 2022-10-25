#include <string>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;

    const int bin = 20;

    // 1. bitset을 활용한 이진수 변환
    string str = bitset<bin>(n).to_string();

    int ind_1 = -1;
    int ind_0 = -1;
    int cnt_1 = 0;
    bool found = false;
    // 2. 가장 마지막에 위치한 1을 찾아냅니다.
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (found == true && str[i] == '0')
        {
            str[i] = '1';
            ind_0 = i;
            break;
        }
        if (found == true && str[i] == '1')
        {
            str[i] = '0';
            cnt_1++;
        }
        if (found == false && str[i] == '1')
        {
            str[i] = '0';
            ind_1 = i;
            found = true;
        }
    }

    // 3. 마지막 1위로 가장 가까운 0을 찾아서 1로 변경해줍니다.
    string str2 = "1";
    if (ind_0 >= 0)
    {
        str[ind_0] = '1';
        str2 = str;
    }
    else
    {
        str2.append(str);
    }

    // 4. 1 에서 0으로 바꾼 'i' 기준 밑으로 1들을 붙여줍니다.
    for (int i = 0; i < cnt_1; i++)
    {
        str2[str2.size() - 1 - i] = '1';
    }

    // 5. 2진법 -> 10진법
    int power = 0;
    for (int i = str2.size() - 1; i >= 0; i--)
    {
        answer += ((str2[i] - '0') * pow(2, power));
        power++;
    }

    return answer;
}