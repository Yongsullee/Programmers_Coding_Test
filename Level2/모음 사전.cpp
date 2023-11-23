#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt = -1;
string target = "";
string aeiou = "AEIOU";

// #1. 깊이 우선 탐색 : target 문자열이 완성되기 전까지 "AEIOU"중 한 문자를 이어붙여가며 재귀적으로 검사
void dfs(string str)
{
    cnt++;
    
    if(str == target)
    {
        answer = cnt;
        return;
    }
    
    if(str.length() >= 5) return;
    
    for(int i=0; i<5; i++)
        dfs(str + aeiou[i]);
}

int solution(string word) {

    target = word;
    
    dfs("");
    
    return answer;
}