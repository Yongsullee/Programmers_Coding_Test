/*
    풀이:
        n진법 < - > 10진법
    설명:

        10진법 -> 3진법

        while(n >0)
        {
            str += ((n%3)+'0');
            n /= 3;
        }

        :   N진법의 경우 주어진 숫자를 N으로 나눈 나머지 값을 순서대로 컨테이너에 저장
            그 후, 숫자가 0보다 작을 때까지 N으로 나눕니다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string str = "";
    // 1. 10진법 -> 3진법
    while(n > 0)
    {
        str += ((n%3)+'0');
        n /= 3;
    }
    
    // 2. 3진법 -> 10진법
    int power = 0;
    for(int i=(int)str.size()-1; i>=0; i--)
    {
        answer += ((str[i]-'0')*pow(3, power));
        power++;
    }
    
    return answer;
}