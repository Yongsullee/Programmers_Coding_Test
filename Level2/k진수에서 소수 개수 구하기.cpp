// 실패 코드

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

string ConverToK(int n, int k)
{
    string res = "";

    while (n > 0)
    {
        int r = n % k;

        res = to_string(r) + res;
        n /= k;
    }
    return res;
}

bool IsPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    int ans = 0;
    string str = ConverToK(n, k);

    // #1. 오른쪽 끝 숫자가 소수인지?
    int startIdx = -1;
    bool makeString = false;
    string tmp = "";
    for (int i = 0; i < str.length(); ++i)
    {
        // #1. 0이 아닐 경우, 현재 위치의 문자를 임시 문자열에 삽입합니다.
        if (str[i] != '0')
        {
            tmp += str[i];
            // 시작 지점 체크
            if (!makeString)
            {
                startIdx = i;
                makeString = true;
            }
        }
        // 0을 만나면 체크합니다.
        else
        {
            if (!tmp.empty() && IsPrime(stoi(tmp)))
            {
                // #1 0P0 조건
                if (startIdx - 1 >= 0 && i + 1 < str.length() && str[startIdx - 1] == '0' && str[i + 1] == '0')
                    ans++;

                // #2.P0 조건
                if (i + 1 < str.length() && str[i + 1] == '0')
                    ans++;

                // #3.0P
                if (startIdx - 1 >= 0 && str[startIdx - 1] == '0')
                    ans++;

                // #4. P
                if (startIdx == 0 && i + 1 == str.length())
                    ans++;

                // 초기화
                tmp.clear();
                makeString = false;
            }
        }
    }

    return ans;
}

// 정답 코드

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

string ConverToK(int n, int k)
{
    string res = "";

    while (n > 0)
    {
        int r = n % k;

        if (r < 10)
            res = to_string(r) + res;
        else
            res = char('A' + r - 10) + res;
        n /= k;
    }
    return res;
}

bool IsPrime(long long num)
{
    if (num < 2)
        return false;

    for (long long i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    int ans = 0;
    // #1. 문자열의 마지막에 0을 추가함으로서, 마지막으로 찾은 소수에 대한 검사 작업이 이루어지도록 합니다.
    string str = ConverToK(n, k) + "0";

    long long tmp = 0;
    for (auto c : str)
    {
        // #2. 0을 만나면, 지금까지 계산한 숫자에 * 10을 해주어 새로 추가될 숫자가 뒤에 오도록 설정해줍니다.
        if (c != '0')
            tmp = tmp * 10 + (c - '0');
        else
        {
            if (IsPrime(tmp))
            {
                ans++;
            }
            tmp = 0;
        }
    }

    return ans;
}