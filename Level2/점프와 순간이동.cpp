#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int res = n;
    while(true)
    {
        if(res%2 == 1)
            ans++;
        
        res /= 2;
        if(res == 1)
        {
            ans++;
            break;
        }
        else if(res == 0)
        {
            break;
        }
    }


    return ans;
}