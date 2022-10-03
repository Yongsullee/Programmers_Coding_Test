/*
    1번 코드 성공
*/

#include <string>
#include <vector>

using namespace std;

vector<int> fib(100001, 0);

int solution(int n) {
    int answer = 0;
    
    fib[1] = fib[2] = 1;
    
    for(int i=3; i<=n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= 1234567;
    }
    
    return fib[n];
}

/*
    2번 코드 실패, 왜인지는 잘...
*/

#include <string>
#include <vector>

using namespace std;

vector<int> fib(100001, 0);

int solution(int n) {
    int answer = 0;
    
    fib[1] = fib[2] = 1;
    
    for(int i=3; i<=n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib[n]%1234567;
}