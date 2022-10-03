/*
    * 주의 : 입력 받은 수가 1일 경우 "2"를 출력합니다!
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int num = (n+1)/2;
    int sum = 0;
    int j = 1;
    
    for(int i=1; i <= num; i++)
    {
        sum += i;
        
        if(sum >= n)
        {
            while(sum > n) sum -= j++;
            if( sum == n)
                answer++;
        }
    }
    
    if(n != 1)
        return answer;
    else
        return 1;
}