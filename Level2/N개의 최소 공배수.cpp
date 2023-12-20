#include <string>
#include <vector>

using namespace std;

/*

    a, b, 그리고 c의 최소 공배수는 lcm(lcm(a,b), c) 와 같습니다.

*/

int gcd(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr)
{
    int answer = 0;

    if ((int)arr.size() < 2)
        return arr[0];

    answer = lcm(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); ++i)
    {
        answer = lcm(answer, arr[i]);
    }

    return answer;
}