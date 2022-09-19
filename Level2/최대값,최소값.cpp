/*
    stoi(음수 문자열), eg) "-15", "-16", etc

    : 가능하다!
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string numStr = "";
    vector<int> v;
    
    for(int i=0; i<s.size(); i++)
    {
        // 1. 공백
        if(s[i] == ' ')
        {
            v.push_back(stoi(numStr));
            numStr.clear();
        }
        // 2. 마지막 문자
        else if(i == s.size()-1)
        {
            numStr += s[i];
            v.push_back(stoi(numStr));
        }
        // 3. 공백을 제외한 문자
        else
        {
            numStr += s[i];
        }
    }
    
    sort(begin(v), end(v));
    
    answer.append(to_string(v.front()));
    answer += ' ';
    answer.append(to_string(v.back()));
    
    return answer;
}