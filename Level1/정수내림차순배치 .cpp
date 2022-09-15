// 1. char to int = -'0'
// 2. int to char = +'0'
// 3. stoi, stol, stof, stod 활용

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> v;
        
    string str = to_string(n);
    
    for(int i=0; i<str.size(); i++)
    {
        v.push_back(str[i]-'0');
    }
    
    str.clear();
    sort(begin(v), end(v), greater<>());
    
    for(int i=0; i<v.size(); i++)
        str += (v[i]+'0');
    
    answer = stol(str);
    
    return answer;
}